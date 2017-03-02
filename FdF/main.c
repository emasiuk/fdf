/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:07:17 by emasiuk           #+#    #+#             */
/*   Updated: 2017/02/23 15:07:18 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_cords *cd)
{
	int		i;
	double	x;
	double	y;

	i = -1;
	while (cd[++i].stop != 0)
	{
		x = (cd[i].x * cd[0].scale_all * cos(cd[0].beta) +
		(-cd[i].y * cd[0].scale_all * sin(cd[0].alfa) +
		cd[i].z * cd[0].scale_all * cos(cd[0].alfa) * cd[0].scale_z)
		* sin(cd[0].beta)) * cos(cd[0].gama) +
		(cd[i].y * cd[0].scale_all * cos(cd[0].alfa)
		+ cd[i].z * cd[0].scale_all * sin(cd[0].alfa) * cd[0].scale_z)
		* sin(cd[0].gama);
		y = -(cd[i].x * cd[0].scale_all * cos(cd[0].beta) +
		(-cd[i].y * cd[0].scale_all * sin(cd[0].alfa) + cd[i].z *
		cd[0].scale_all * cos(cd[0].alfa) * cd[0].scale_z) * sin(cd[0].beta)) *
		sin(cd[0].gama) + (cd[i].y * cd[0].scale_all * cos(cd[0].alfa)
		+ cd[i].z * cd[0].scale_all * sin(cd[0].alfa)
		* cd[0].scale_z) * cos(cd[0].gama);
		cd[i].x1 = 300 + x * cd[0].scale_x;
		cd[i].y1 = 700 + y * cd[0].scale_y;
		mlx_pixel_put(cd[0].mlx, cd[0].win, cd[i].x1, cd[i].y1, cd[i].color);
	}
	bresenham(cd);
}

void	make_window(t_cords *cd)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	cd[0].mlx = mlx;
	cd[0].win_size_x = 1280;
	cd[0].win_size_y = 1024;
	win = mlx_new_window(cd[0].mlx, cd[0].win_size_x, cd[0].win_size_y, "test");
	cd[0].win = win;
	draw(cd);
	mlx_key_hook(cd[0].win, my_key_funct, cd);
	mlx_loop(cd[0].mlx);
}

void	fill_arr(char *str, t_cords *cd, int y, int *n)
{
	int		i;
	char	**temp;
	int		x;
	char	**tmp;

	i = -1;
	x = -1;
	temp = ft_strsplit(str, ' ');
	while (temp[++i])
	{
		tmp = ft_strsplit(temp[i], ',');
		cd[++*n].z = ft_atoi(temp[i]);
		if (tmp[1])
			cd[*n].color = ft_atoi_base(tmp[1] + 2, 16);
		else
			cd[*n].color = ft_atoi_base("ffffff", 16);
		cd[*n].x = ++x;
		cd[*n].y = y;
		cd[*n].stop = 1;
		free(tmp);
	}
	free(temp);
}

int		main(int argc, char *argv[])
{
	char		*str;
	int			fd;
	t_cords		*cd;
	int			y;
	static int	n;

	n = -1;
	cd = (t_cords *)malloc(sizeof(t_cords) * 2500000);
	y = -1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &str) == 1)
			fill_arr(str, cd, ++y, &n);
		cd[++n].stop = 0;
		lf_max(cd);
		close(fd);
		cd[0].alfa = -70 * RAD;
		cd[0].beta = 25 * RAD;
		cd[0].gama = 10 * RAD;
		make_window(cd);
	}
	else
		return (0);
}
