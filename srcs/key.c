/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:31:30 by efichot           #+#    #+#             */
/*   Updated: 2017/01/06 17:41:08 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	key_move(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
}

int		key_press(int keycode, t_env *e)
{
	key_move(keycode, e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	key_move(keycode, e);
	return (0);
}
