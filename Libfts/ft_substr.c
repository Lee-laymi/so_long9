/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:09:42 by skrairab          #+#    #+#             */
/*   Updated: 2022/04/10 20:27:59 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l >= len)
		str = (char *)malloc(len + 1);
	else
		str = (char *)malloc(l + 1);
	if (!str)
		return (NULL);
	while (start < l && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
