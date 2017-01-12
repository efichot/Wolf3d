/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:02:10 by efichot           #+#    #+#             */
/*   Updated: 2017/01/12 15:31:54 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct	s_ixy
{
	int			x;
	int			y;
}				t_ixy;

typedef struct	s_dxy
{
	double		x;
	double		y;
}				t_dxy;

typedef struct	s_player
{
	t_dxy		pos;
	t_dxy		dir;
	t_dxy		plane;
	int			z;
}				t_player;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pxl;
	int			bpp;
	int			s_line;
	int			ed;
}				t_mlx;

typedef struct	s_ray
{
	t_dxy		pos;
	t_dxy		dir;
	t_ixy		map;
	t_dxy		side;
	t_dxy		delta;
	t_dxy		step;
	double		dist;
	double		cam;
	int			hit;
	int			hit_side;
}				t_ray;

typedef struct	s_env
{
	t_player		player;
	t_ray			ray;
	t_mlx			mlx;
	int				width;
	int				height;
	int				map_width;
	int				map_height;
	int				**map;
	unsigned int	color1;
	unsigned int	color2;
	unsigned int	color3;
	unsigned int	color4;
	unsigned int	color_sky;
	unsigned int	color_ground;
	int				start_x;
	int				start_y;
}				t_env;

int		init_env(t_env *e);
void	init_player(t_env *e);
void	init_mlx(t_env *e);
int		arg_open(int ac, char **av, t_env *e);
int		error_map(void);
int		open_file(t_env *e, char *file);
int		read_file(int fd, t_env *e);
int		read_pos(int fd, t_env *e);
int		read_line(char *line, int y, int **map, t_env *e);
int		key_hook(int keycode, t_env *e);
int		key_press(int keycode, t_env *e);
void	key_move(int keycode, t_env *e);
int		loop_hook(t_env *e);
void	raycasting(t_env *e);
void	ray_init(t_env *e, int x);
void	ray_cal_step_side(t_env *e);
void	ray_cal_dist(t_env *e);
void	ray_draw(t_env *e, int x);
void	draw_line(t_env *e, int x, int start, int end);
void	put_pxl(t_env *e, int x, int y, unsigned int color);

#endif
