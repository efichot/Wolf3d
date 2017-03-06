/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:43:11 by efichot           #+#    #+#             */
/*   Updated: 2017/01/19 17:40:36 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void	move_right(t_env *e)
{
	double	oldx;
	double	oldpx;

	oldx = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(-(e->player.speed_turn)) -
		e->player.dir.y * sin(-(e->player.speed_turn));
	e->player.dir.y = oldx * sin(-(e->player.speed_turn)) +
		e->player.dir.y * cos(-(e->player.speed_turn));
	oldpx = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(-(e->player.speed_turn)) -
		e->player.plane.y * sin(-(e->player.speed_turn));
	e->player.plane.y = oldpx * sin(-(e->player.speed_turn)) +
		e->player.plane.y * cos(-(e->player.speed_turn));
}

void	move_left(t_env *e)
{
	double	oldx;
	double	oldpx;

	oldx = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(e->player.speed_turn) -
		e->player.dir.y * sin(e->player.speed_turn);
	e->player.dir.y = oldx * sin(e->player.speed_turn) +
		e->player.dir.y * cos(e->player.speed_turn);
	oldpx = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(e->player.speed_turn) -
		e->player.plane.y * sin(e->player.speed_turn);
	e->player.plane.y = oldpx * sin(e->player.speed_turn) +
		e->player.plane.y * cos(e->player.speed_turn);
}

void	move_forward_backward(int keycode, t_env *e)
{
	if (keycode == 126 || keycode == 13)
	{
		if (e->map[(int)(e->player.pos.x + e->player.dir.x *
			e->player.speed_move)][(int)(e->player.pos.y)] == 0)
			e->player.pos.x += e->player.dir.x * e->player.speed_move;
		if (e->map[(int)(e->player.pos.x)][(int)(e->player.pos.y +
			e->player.dir.y * e->player.speed_move)] == 0)
			e->player.pos.y += e->player.dir.y * e->player.speed_move;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (e->map[(int)(e->player.pos.x - e->player.dir.x *
			e->player.speed_move)][(int)(e->player.pos.y)] == 0)
			e->player.pos.x -= e->player.dir.x * e->player.speed_move;
		if (e->map[(int)(e->player.pos.x)][(int)(e->player.pos.y -
			e->player.dir.y * e->player.speed_move)] == 0)
			e->player.pos.y -= e->player.dir.y * e->player.speed_move;
	}
}

void	key_move(int keycode, t_env *e)
{
	move_forward_backward(keycode, e);
	move_lateral(keycode, e);
	if (keycode == 123)
		move_left(e);
	if (keycode == 124)
		move_right(e);
	if (keycode == 49)
		e->player.jump = !e->player.jump;
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
}
