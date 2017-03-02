/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:00:05 by emasiuk           #+#    #+#             */
/*   Updated: 2017/02/23 15:00:05 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check(int y0, int x1, int y1, t_cords *cd)
{
	int x0;

	x0 = cd[cd[0].m].x1;
	(x0 < x1) ? (cd[0].sx = 1) : 1;
	(x0 > x1) ? (cd[0].sx = -1) : 1;
	(y0 < y1) ? (cd[0].sy = 1) : 1;
	(y0 > y1) ? (cd[0].sy = -1) : 1;
}

void		line(int y0, int x1, int y1, t_cords *cd)
{
	int x0;

	x0 = cd[cd[0].m].x1;
	cd[0].dx = abs(x1 - x0);
	cd[0].dy = -abs(y1 - y0);
	cd[0].err = cd[0].dx + cd[0].dy;
	check(y0, x1, y1, cd);
	while (1)
	{
		mlx_pixel_put(cd[0].mlx, cd[0].win, x0, y0, cd[cd[0].m].color);
		if (x0 == x1 && y0 == y1)
			break ;
		cd[0].e2 = 2 * cd[0].err;
		if (cd[0].e2 > cd[0].dy)
		{
			cd[0].err += cd[0].dy;
			x0 += cd[0].sx;
		}
		if (cd[0].e2 < cd[0].dx)
		{
			cd[0].err += cd[0].dx;
			y0 += cd[0].sy;
		}
	}
}

void		bresenham(t_cords *cd)
{
	int i;
	int k;

	i = -1;
	k = -1;
	cd[0].m = 0;
	while (cd[++i].stop != 0 && cd[i + 1].stop != 0)
	{
		if (cd[i].y != cd[i + 1].y)
			;
		else
		{
			cd[0].m = i;
			line(cd[i].y1, cd[i + 1].x1, cd[i + 1].y1, cd);
		}
		while (cd[++k].stop != 0)
			if (cd[k].x == cd[i].x && cd[i].y + 1 == cd[k].y)
			{
				cd[0].m = i;
				line(cd[i].y1, cd[k].x1, cd[k].y1, cd);
				break ;
			}
	}
}
