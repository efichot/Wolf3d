/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:58:30 by efichot           #+#    #+#             */
/*   Updated: 2017/01/19 22:11:05 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	ret = NULL;
	if (!s)
		return (NULL);
	if (!(ret = ft_strnew(len)))
	{
		ft_strdel(&ret);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	return (ret);
}
