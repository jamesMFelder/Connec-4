/**
 *  * Player.h
 *   *
 *    * Copyright 2020 James <james.m.felder@gmail.com>
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

#ifndef PLAYER_H
#define PLAYER_H

#include "connect_4_grid.h"

class player {
	public:
			player();
			int set_color(char);
			int set_grid(Connect_4_grid *);
			int play();
	private:
			char color;
			Connect_4_grid *grid;
			int getNum();
};
#endif
