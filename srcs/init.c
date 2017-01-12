/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:32:12 by efichot           #+#    #+#             */
/*   Updated: 2017/01/12 16:50:33 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_player(t_env *e)
{
	e->player.pos.x = 0;
	e->player.pos.y = 0;
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.z = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
}

void	init_mlx(t_env *e)
{
	e->mlx.mlx = mlx_init();
	e->mlx.bpp = 0;
	e->mlx.s_line = 0;
	e->mlx.img = mlx_new_image(e->mlx.mlx, e->width, e->height);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp), &(e->mlx.s_line),
		&(e->mlx.ed));
}

int		init_env(t_env *e)
{
	e->width = WIDTH;
	e->height = HEIGHT;
	init_player(e);
	init_mlx(e);
	e->color1 = 0x4f5069;
	e->color2 = 0xC09C65;
	e->color3 = 0x808184;
	e->color4 = 0x668E7E;
	e->color_sky = 0x4f98e3;
	e->color_ground = 0x4e310b;
	return (1);
}
