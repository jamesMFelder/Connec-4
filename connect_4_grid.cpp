/**
 * conect_4_grid.cpp
 *
 * Copyright 2019 James <james.m.felder@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include "connect_4_grid.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;


Connect_4_grid::Connect_4_grid(){
    int h, w;
    win_status=0;
    for(w=0;w<FGW;w++){
        for(h=0;h<FGH;h++){
            grid[w][h]='E';
        }
    }
    for(w=1;w<=GW;w++){
        for(h=1;h<GH;h++){
            grid[w][h]=' ';
        }
    }
}

int Connect_4_grid::addPiece(int spot, char color){
    int height;//declaration

    if(spot > GW || spot < 1 ){
	    cerr << "GW=" << GW << " and you chose spot: " << spot << endl;
        cerr << "Bad choice. Try again." << endl;
        return 2;
    }//check that the top is empty and spot is valid.
    else if (grid[spot][GH-1] != ' '){
	    cerr << "Column " << spot << " is full. Please try again." << endl;
	    return 2;
    }

    for(height=GH;grid[spot][height-1] == ' '; height--){
        if(height==0){
            break;
        }
    }//find the lowest spot

    grid[spot][height]=color;//set it to the person's letter

    cout << "\033[2J" << endl;
    set_win(color, spot, height);

    return 0;
}


void Connect_4_grid::print(){
    int i, j;
	cout << "--------------\n";
    for(i=GH-1;i>0;i--){
        for(j=1;j<=GW;j++){
            cout << "|" << grid[j][i];
        }
        cout << "|\n--------------" << endl;
    }
    cout <<  " 1 2 3 4 5 6 7" << endl;
}

int Connect_4_grid::check_win(){
    return win_status;
}

//A straight foreward if else sequence to check for three (in a row) and set where to the only place you can stop it.
int Connect_4_grid::where_win(char turn, int &where){
    int width;
    int height;
    for(width=1; width<=GW; width++){
	    for(height=1; height<=GH; height++){
		    if(grid[width][height]==turn){
			    if(grid[width][height-1]==turn && grid[width][height-2]==turn &&\
					grid[width][height+1]==' '){where=width; return 0;}//straight down


			    if(grid[width+1][height]==turn && grid[width+2][height]==turn){
					if(grid[width+3][height]==' ' && (height==0 || grid[width+3][height-1]!=' ')){where=width+3; return 0;}//straight to the right
					else if(grid[width-1][height]==' ' && grid[width-1][height-1]!=' '){where=width-1; return 0;}}

			    if(grid[width+2][height]==turn && grid[width+3][height]==turn){ //missing spot two
					if(grid[width+1][height]==' ' && (height==0 || grid[width+1][height-1]!=' ')){where=width+1; return 0;}}//straight to the right

			    if(grid[width+1][height]==turn && grid[width+3][height]==turn){ //missing spot three
					if(grid[width+2][height]==' ' && (height==0 || grid[width+2][height-1]!=' ')){where=width+2; return 0;}}//straight to the right

			    
			    if(grid[width+1][height+1]==turn && grid[width+2][height+2]==turn){
					if(grid[width+3][height+3]==' ' && grid[width+3][height+2]!=' '){where=width+3; return 0;}//up and to the right
					else if(grid[width-1][height-1]==' ' && grid[width-1][height-2]!=' '){where=width-1; return 0;}}

			    if(grid[width+2][height+2]==turn && grid[width+3][height+3]==turn){//missing spot two
					if(grid[width+1][height+1]==' ' && grid[width+1][height]!=' '){where=width+1; return 0;}}//up and to the right

			    if(grid[width+1][height+1]==turn && grid[width+3][height+3]==turn){//missing spot three
					if(grid[width+2][height+2]==' ' && grid[width+2][height+1]!=' '){where=width+2; return 0;}}//up and to the right


			    if(grid[width+1][height-1]==turn && grid[width+2][height-2]==turn){
					if(grid[width+3][height-3]==' ' && (height==3 || grid[width+3][height-4]!=' ')){where=width+3; return 0;}//down and to the right
					else if(grid[width-1][height+1]==' ' && grid[width-1][height]!=' '){where=width+3; return 0;}}

			    if(grid[width+2][height-2]==turn && grid[width+3][height-3]==turn){//missing spot two
					if(grid[width+1][height-1]==' ' && grid[width+1][height-2]!=' '){where=width+1; return 0;}}//down and to the right

			    if(grid[width+1][height-1]==turn && grid[width+3][height-3]==turn){//missing spot three
					if(grid[width+2][height-2]==' ' && grid[width+2][height-3]!=' '){where=width+2; return 0;}}//down and to the right
		    }
	    } 
    }
    return 1;
}

void Connect_4_grid::set_win(char turn, int width, int height){
    char status='l';
    int i, j, count;
    while(true){//just allows me to use a break statement
    for(count=0, j=width; grid[j][height] == turn; j--, count++){
    }//see how far left it goes
    if(count >=4){
        status='w';
        break;
    }//return if 4

    for(count=count-1, j=width; grid[j][height] == turn; j++, count++){
    }//see how far right it goes
    if(count >=4){
        status='w';
        break;
    }//return if 4

    for(count=0, j=height; grid[width][j] == turn; j--, count++){
    }//see how far down it goes
    if(count >=4){

        status='w';
        break;
    }//return if 4

    for(count=0, i=height, j=width; grid[j][i] == turn; j--, i++, count++){
    }//see how far up-left it goes
    if(count >=4){

        status='w';
        break;
    }//return if 4

    for(count=count-1, i=height, j=width; grid[j][i] == turn; j++, i--, count++){
    }//see how far down-right it goes
    if(count >=4){
        status='w';
        break;
    }//return if 4

    for(count=0, i=height, j=width; grid[j][i] == turn; j--, i--, count++){
    }//see how far down-left it goes
    if(count >=4){

        status='w';
        break;
    }//return if 4

    for(count=count-1, i=height, j=width; grid[j][i] == turn; j++, i++, count++){
    }//see how far up-right it goes
    if(count >=4){

        status='w';
        break;
    }//return if 4
    break;
    }//ends the infinite while loop
    if(status=='w'){
        if(turn=='R'){
            win_status=RED_WIN;
        }
        else{
            win_status=YELLOW_WIN;
        }
	print();
        print_exit();
    }//if a win
}

int Connect_4_grid::check_tie(){
    int i;
    for(i=0;i<GW;i++){//loop through the top
        if(grid[i][GH] == ' '){//if any are empty:
            return 0;//it is not a tie
        }//end if
    }//end loop
    return TIE;
}//end check_tie

void Connect_4_grid::print_exit(){
    int i;
    i=check_win();
    if(i==RED_WIN){
        cout << "Red wins!" << endl;
    }
    else if(i==YELLOW_WIN){
        cout << "Yellow wins!" << endl;
    }
    else if(i==TIE){
        cout << "Tie!" << endl;
    }
    else{
        cout << "Sorry you couldn't finish your game. :( Try again later." << endl;
    }
}
