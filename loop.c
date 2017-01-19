/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:46:26 by efichot           #+#    #+#             */
/*   Updated: 2017/01/19 16:41:15 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

int		loop_hook(t_env *e)
{
	raycasting(e);
	if (e->player.jump)
	{
		if (e->player.z <= 25)
			e->player.z += 25;
	}
	if (!(e->player.jump) && e->player.z)
		e->player.z -= 25;
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	return (0);
}
