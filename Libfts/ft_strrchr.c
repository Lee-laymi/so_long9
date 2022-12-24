/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:48:46 by skrairab          #+#    #+#             */
/*   Updated: 2022/03/27 16:09:06 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen((char *)s);
	s += s_len;
	if (s == NULL)
		return (NULL);
	while (s_len > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s_len--;
		s--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
