/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:04:24 by efichot           #+#    #+#             */
/*   Updated: 2017/01/06 17:45:01 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		error_map(void)
{
	ft_putstr_fd("Error map.\n", 2);
	exit(0);
	return (0);
}

int		arg_open(int ac, char **av, t_env *e)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error argv <filename> <map>.\n", 2);
		return (0);
	}
	if (!(open_file(e, av[1])))
	{
		error_map();
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))) || !(init_env(e)))
	{
		free(e);
		exit(0);
		return (0);
	}
	if (!(arg_open(ac, av, e)))
		return (0);
	init_mlx(e);
	e->mlx.win = mlx_new_window(e->mlx.mlx, e->width, e->height,
		"Wolf3d efichot@42");
	//mlx_do_key_autorepeatoff(e->mlx.mlx);
	mlx_loop_hook(e->mlx.mlx, loop_hook, e);
	mlx_hook(e->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, e);
	mlx_key_hook(e->mlx.win, key_hook,e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
