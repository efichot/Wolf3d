/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_smog.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:50:49 by efichot           #+#    #+#             */
/*   Updated: 2017/03/13 13:49:37 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void			put_pxl(t_env *e, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * e->mlx.s_line);
	e->mlx.pxl[i] = color;
	e->mlx.pxl[++i] = color >> 8;
	e->mlx.pxl[++i] = color >> 16;
}

int				get_color(t_env *e)
{
	if (e->ray.hit_side == 1)
	{
		if (e->ray.step.y == -1)
			return (e->color1);
		if (e->ray.step.y == 1)
			return (e->color2);
	}
	if (e->ray.step.x == -1)
		return (e->color3);
	return (e->color4);
}

unsigned int	add_smog_sky(unsigned char r, unsigned char g,
	unsigned char b, double dist)
{
	r = r * dist * dist * dist;
	g = g * dist * dist * dist;
	b = b * dist * dist * dist;
	return ((r << 16) + (g << 8) + b);
}

unsigned int	add_smog(unsigned int c, double dist, int area)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	if (area == 1)
		dist = dist / 300;
	else if (area == 2)
		dist = dist / 1200;
	else
		dist = dist / 6;
	if (dist > 0.9)
		dist = 0.9;
	if (area == 2)
		return (add_smog_sky(r, g, b, dist));
	else
	{
		r = r - (r * dist);
		g = g - (g * dist);
		b = b - (b * dist);
	}
	return ((r << 16) + (g << 8) + b);
}

void			draw_line(t_env *e, int x, int start, int end)
{
	unsigned int	color;
	int				i;

	i = -1;
	color = get_color(e);
	color = add_smog(color, e->ray.dist, 0);
	while (++i < start + e->player.z)
		put_pxl(e, x, i, add_smog(e->color_sky, e->height - i, 2));
	i--;
	while (++i <= end + e->player.z && i < e->height)
		put_pxl(e, x, i, color);
	i--;
	while (++i < e->height)
		put_pxl(e, x, i, add_smog(e->color_ground, e->height - i, 1));
}
