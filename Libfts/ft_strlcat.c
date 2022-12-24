/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:56:59 by skrairab          #+#    #+#             */
/*   Updated: 2022/03/09 18:38:46 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (dst[j] && j < dstsize)
		j++;
	i = j;
	while (src [j - i] && j + 1 < dstsize)
	{
		dst[j] = src[j - i];
		j++;
	}
	if (i < dstsize)
		dst[j] = '\0';
	return (i + ft_strlen(src));
}
