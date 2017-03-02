/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:18:51 by emasiuk           #+#    #+#             */
/*   Updated: 2017/02/23 16:18:52 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		scale(t_cords *cd)
{
	cd[0].scale_x = 1000 / (cd[0].max_x * 1.7);
	cd[0].scale_y = 1000 / (cd[0].max_y * 1.7);
	cd[0].scale_z = (cd[0].max_z / 10) / cd[0].max_z;
	cd[0].scale_all = 1;
	if (cd[0].max_z == 0)
		cd[0].scale_z = 1;
	if (cd[0].max_z < 30 && cd[0].max_z > 0)
		cd[0].scale_z = (cd[0].max_z / 2) / cd[0].max_z;
}

void		lf_max(t_cords *cd)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 0;
	cd[0].max_x = 0;
	cd[0].max_y = 0;
	cd[0].max_z = 0;
	while (y <= cd[i].y)
	{
		x = 0;
		while (cd[++i].x >= 0 && cd[i].x && y == cd[i].y)
		{
			if (cd[0].max_z < cd[i].z)
				cd[0].max_z = cd[i].z;
			x++;
		}
		if (cd[0].max_x < x)
			cd[0].max_x = x;
		y++;
		i++;
	}
	cd[0].max_y = y - 1;
	scale(cd);
}
