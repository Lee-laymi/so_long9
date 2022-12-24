/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:18:57 by skrairab          #+#    #+#             */
/*   Updated: 2022/03/09 16:09:32 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < (destsize - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (i < destsize)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}
