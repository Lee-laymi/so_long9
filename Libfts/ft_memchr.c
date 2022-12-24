/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:16:04 by skrairab          #+#    #+#             */
/*   Updated: 2022/03/20 14:19:22 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*a;

	i = 0;
	if (s == NULL)
		return (NULL);
	a = (void *)s;
	while (i < n)
	{
		if (a[i] == (char)c)
			return (&a[i]);
		i++;
	}
	return (NULL);
}
