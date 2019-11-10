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

//compile with comect_4_grid.cpp!

#include "conect_4_grid.h"
#include <iostream>
using namespace std;

int main(){
    short int i, j, choice;
    Conect_4_grid c;
    c.print();
    for(i=0;c.check_win() == 0;i++){
        if(i%2 == 0){
            cout << "Red's turn: ";
            cin >> choice;
            j=c.addPiece(choice-1, 'R');
            i=i-2;
        }
        else{
            cout << "Yellow's turn: ";
            cin >> choice;
            j=c.addPiece(choice-1, 'Y');
        }
        if(j==-1){
            --i;
        }
    }
    return 0;
}

