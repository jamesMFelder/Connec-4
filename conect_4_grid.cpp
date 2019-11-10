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

#define GH 6
#define GW 7
#define TIE 3
#define RED_WIN 4
#define YELLOW_WIN 5

#include "conect_4_grid.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::clog;


Conect_4_grid::Conect_4_grid(){
    int h, w;
    win_status=0;
    for(w=0;w<GW;w++){
        for(h=0;h<GH;h++){
            grid[w][h]=' ';
        }
    }
}

int Conect_4_grid::addPiece(int spot, char color){
    int height;//declaration

    if(grid[spot][GH-1] != ' '){
        cout << "Bad choice. Try again." << endl;
        return -1;
    }//check that the top is empty

    for(height=GH-1;grid[spot][height-1] == ' '; height--){
        if(height==0){
            break;
        }
    }//find the lowest spot

    grid[spot][height]=color;//set it to Red (it's red's turn)

    print();//output the grid

    set_win(color, spot, height);

    return 0;
}


void Conect_4_grid::print(){
    int i, j;
	cout << "---  ---  ---  ---  ---  ---  ---\n";
    for(i=GH-1;i>=0;i--){
        for(j=0;j<GW;j++){
            cout << "|" << grid[j][i] << "|  ";
        }
        cout << "\n---  ---  ---  ---  ---  ---  ---" << endl;
    }
}

int Conect_4_grid::check_win(){
    return win_status;
}

void Conect_4_grid::set_win(char turn, int width, int height){
    char status;
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
        if(turn=='R' || turn=='r'){
            win_status=RED_WIN;
        }
        else{
            win_status=YELLOW_WIN;
        }
        print_exit();
    }//if a win
}

int Conect_4_grid::check_tie(){
    int i;
    for(i=0;i<GW;i++){//loop through the top
        if(grid[i][GH] == ' '){//if any are empty:
            return 0;//it is not a tie
        }//end if
    }//end loop
    return TIE;
}//end check_tie

void Conect_4_grid::print_exit(){
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
