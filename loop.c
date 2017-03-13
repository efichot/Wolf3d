/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:46:26 by efichot           #+#    #+#             */
/*   Updated: 2017/01/20 12:19:44 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

int		loop_hook(t_env *e)
{
	raycasting(e);
	if (e->player.jump)
	{
		if (e->player.z <= 50)
			e->player.z += 50;
	}
	if (e->player.sprint)
	{
		if (e->player.speed_move == 0.2)
			e->player.speed_move -= 0.1;
		else
			e->player.speed_move += 0.1;
	}
	if (!(e->player.jump) && e->player.z)
		e->player.z -= 50;
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	return (0);
}
