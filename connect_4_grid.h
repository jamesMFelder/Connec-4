/**
 * connect_4_grid.h
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


#ifndef CONECT_4_GRID_H
#define CONECT_4_GRID_H

#define GH 6
#define FGH 8
#define GW 7
#define FGW 9
#define TIE 3
#define RED_WIN 4
#define YELLOW_WIN 5

class Connect_4_grid
{
    public:
        Connect_4_grid();

        int addPiece(int, char);//generic turn, takes a spot and 'R', or 'Y' for turn

	int where_win(char, int &);
        int check_win();//see if the game has ended
       void print();//usefull as a public interface for ->
       /*playing back games*/

    private:

        void set_win(char, int, int);

        int check_tie();
        void print_exit();

        char grid[FGW]/*width*/[FGH];//height
        int win_status;//has someone won?
};

#endif /* CONECT_4_GRID_H */
