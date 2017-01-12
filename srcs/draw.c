/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:50:49 by efichot           #+#    #+#             */
/*   Updated: 2017/01/12 16:48:01 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_pxl(t_env *e, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * e->mlx.s_line);
	e->mlx.pxl[i] = color;
	e->mlx.pxl[++i] = color >> 8;
	e->mlx.pxl[++i] = color >> 16;
}

void	draw_line(t_env *e, int x, int start, int end)
{
	unsigned int	color;
	int				i;

	color = e->color1;
	i = -1;
	while (++i < start + e->player.z)
		put_pxl(e, x, i, e->color_sky);
	i--;
	while (++i <= end + e->player.z && i < e->height)
		put_pxl(e, x, i, color);
	i--;
	while (++i < e->height)
		put_pxl(e, x, i, e->color_ground);
}
