/**
 *  * conect_4_grid.h
 *   *
 *    * Copyright 2019 James <james.m.felder@gmail.com>
 *     *
 *      * This program is free software; you can redistribute it and/or modify
 *       * it under the terms of the GNU General Public License as published by
 *        * the Free Software Foundation; either version 2 of the License, or
 *         * (at your option) any later version.
 *          *
 *           * This program is distributed in the hope that it will be useful,
 *            * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *             * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *              * GNU General Public License for more details.
 *               *
 *                * You should have received a copy of the GNU General Public License
 *                 * along with this program; if not, write to the Free Software
 *                  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *                   * MA 02110-1301, USA.
 *                    *
 *                     *
 *                      */

#include "player.h"
#include <iostream>
#include <random>

player::player(){
	grid=NULL;
}

int player::set_color(char Color){
		if(Color=='Y' || Color=='R') color=Color; 
		else {std::cerr << "set_color must take an argument of 'R' or 'Y'" << std::endl; return 1;}
		return 0;
}

int player::set_grid(Connect_4_grid *Grid){
		grid=Grid;
		return 0;
}

int player::play(){
	int w, j;
	char ncolor;
	if(color=='Y') ncolor='R';
	else ncolor='Y';
	if((*grid).where_win(color, w)==0){
		j=(*grid).addPiece(w, color);
		return 0;
	}
	else if((*grid).where_win(ncolor, w)==0){
		j=(*grid).addPiece(w, color);
		return 0;
	}
	else{
		j=1;
		while(j!=0){
				std::random_device dev;
				std::mt19937 rng(dev());
			        std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7); // distribution in range [1, 7]
				j=(*grid).addPiece(dist7(rng), color);
		}
	}
	return 0;

}
