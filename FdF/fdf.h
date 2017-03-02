/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:16:34 by emasiuk           #+#    #+#             */
/*   Updated: 2017/02/23 17:16:36 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "mlx.h"
# include "math.h"
# define RAD 0.0174533

typedef struct		s_cords
{
	int				x;
	int				y;
	int				z;
	double			x1;
	double			y1;
	int				color;
	double			max_x;
	double			max_y;
	double			max_z;
	double			scale_x;
	double			scale_y;
	double			scale_z;
	double			scale_all;
	double			alfa;
	double			beta;
	double			gama;
	int				stop;
	void			*mlx;
	void			*win;
	int				win_size_x;
	int				win_size_y;
	int				err;
	int				e2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				m;
}					t_cords;

int					my_key_funct(int keycode, t_cords *cd);
int					ft_inbase(char c, int b, char l);
int					check_case(char *str, int b);
int					ft_atoi_base(char *str, int b);

void				make_window(t_cords *cd);
void				draw(t_cords *cd);
void				lf_max(t_cords *cd);
void				scale(t_cords *cd);
void				check(int y0, int x1, int y1, t_cords *cd);
void				fill_arr(char *str, t_cords *cd, int y, int *n);
void				bresenham(t_cords *cd);
void				fill_arr(char *str, t_cords *cd, int y, int *n);
void				line(int y0, int x1, int y1, t_cords *cd);

#endif
