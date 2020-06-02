/**
 * Connect_4.cpp
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

//compile with connect_4_grid.cpp and player.cpp

#include "connect_4_grid.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int two_players(int argc, char **argv);//for two players at the same computer
int computer(int argc, char **argv);//to play against the computer
int usage(int exit_code=0);//for -h for invalid option

//processes command-line arguments and calls either usage, computer, or two-player
int main(int argc, char **argv){
    int count;
    for(count=1;count<argc;count++){//iterate through command-line options
		if(strcmp(argv[count], "--help") == 0 || strcmp(argv[count], "-h") == 0){
			usage(); return 0;//call usage for normal return(0)
		} else if(strcmp(argv[count], "--computer") == 0 || strcmp(argv[count], "-c") == 0){
			return computer(argc, argv);//play against the computer
		} else if(strcmp(argv[count], "--two-players") == 0 || strcmp(argv[count], "-t") == 0){
			return two_players(argc, argv);//play against a human
		} else{
			cerr << "Connect_4: bad option: \"" << argv[count] << "\"" << endl;
			return usage(1);//call usage to print to standard error + return 1
		}
	}
	return computer(argc, argv);//default is to play against the computer
}

//play against another human being
int two_players(int argc, char **argv){
	short int i, j, choice;
    char play_again;
    Connect_4_grid c;
    for(i=4;c.check_win() == 0;i++){//be very carefull changing i(on multiple of 2 red plays, otherwise yellow plays
        if(i%2 == 0){//is it red's turn
		c.print();//print the grid
            cout << "Red's turn: ";
            cin >> choice;
            j=c.addPiece(choice, 'R');//add the choice to the grid
	    cin.get();
            i=i-2;//make an overflow less likely
        }
        else{//yellow's turn
		c.print();
		cout << "Yellow's turn: ";
		cin >> choice;
		j=c.addPiece(choice,'Y');//add the choice to the grid
		cin.get();
        }
        if(j==2){//bad value
            --i;//have the player play again
        }
    }
    cout << "Play again? ";
    cin >> play_again;//ask if they want to play again
    if(play_again=='y' || play_again=='Y'){return two_players(argc, argv);}//if so call this again
    else{cout << "Have a nice day!" << endl;}
	return 0;
}

int computer(int argc, char **argv){
	short int i, j, choice;
	char play_again;
    Connect_4_grid c;
    player p;
    p.set_color('Y');
    p.set_grid(&c);
    for(i=4;c.check_win() == 0;i++){
        if(i%2 == 0){
	    c.print();
            cout << "Red's turn: ";
            cin >> choice;
	    cout << "You choose " << choice << endl;
            j=c.addPiece(choice, 'R');
            i=i-2;
	    cin.get();
        }
        else{
	    j=p.play();
        }
        if(j==2){
            --i;
        }
    }
    cout << "Play again? ";
    cin >> play_again;
    if(play_again=='y' || play_again=='Y'){return main(argc, argv);}
    else{cout << "Have a nice day!" << endl;}
    return 0;
}

int usage(int exit_code){
	char mesg[]="Connect_4: usage: connect_4 [option]\n\
	options:\n\
	  -h --help: display this message\n\
	  -t --two-players: play against another person using the same computer\n\
	  -c --computer: play against the computer\n\
	The default is to play against the computer";
	if(exit_code==0){
		cout << mesg << endl;
		return exit_code;
	} else if(exit_code==1){
		cerr << mesg << endl;
		return exit_code;
	} else{
		cerr << "Unknown value to usage function: " << exit_code << "\nValues should be 0(default) for sucess or 1 for error!" << endl;
		return exit_code;
	}
}
