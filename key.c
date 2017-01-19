/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:31:30 by efichot           #+#    #+#             */
/*   Updated: 2017/01/19 17:40:31 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void	move_jump(t_env *e)
{
	e->player.z += 3;
	if (e->player.z > 0)
		e->player.z = 0;
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
