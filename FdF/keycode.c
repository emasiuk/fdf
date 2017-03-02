/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:16:01 by emasiuk           #+#    #+#             */
/*   Updated: 2017/02/23 16:16:01 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add1(int keycode, t_cords *cd)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].alfa += 1 * RAD;
		draw(cd);
	}
	if (keycode == 124)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].alfa -= 1 * RAD;
		draw(cd);
	}
	if (keycode == 125)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].beta -= 1 * RAD;
		draw(cd);
	}
}

void	add2(int keycode, t_cords *cd)
{
	if (keycode == 116)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].gama += 1 * RAD;
		draw(cd);
	}
	if (keycode == 121)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].gama -= 1 * RAD;
		draw(cd);
	}
	if (keycode == 69)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].scale_z += 0.05;
		draw(cd);
	}
	if (keycode == 78)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].scale_z -= 0.05;
		draw(cd);
	}
}

int		my_key_funct(int keycode, t_cords *cd)
{
	add1(keycode, cd);
	add2(keycode, cd);
	if (keycode == 126)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].beta += 1 * RAD;
		draw(cd);
	}
	if (keycode == 75)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].scale_all -= 0.25;
		draw(cd);
	}
	if (keycode == 67)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].scale_all += 0.25;
		draw(cd);
	}
	return (0);
}
