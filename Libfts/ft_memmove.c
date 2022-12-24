/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:46:39 by skrairab          #+#    #+#             */
/*   Updated: 2022/03/20 12:36:04 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!s && !d)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		d += len;
		s += len;
		while (len > i++)
			*--d = *--s;
	}
	return (dst);
}
