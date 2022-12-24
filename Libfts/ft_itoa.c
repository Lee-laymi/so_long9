/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:20:35 by skrairab          #+#    #+#             */
/*   Updated: 2022/04/10 22:02:51 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size += 1;
		n = (unsigned int)(n * -1);
	}
	while ((unsigned int)n / 10 > 0)
	{
		size += 1;
		n = (unsigned int)n / 10;
	}
	return (size + 1);
}

static char	*ft_fillnbr(char *nbr, long n, int i)
{
	if (n == 0)
		nbr[i] = '0';
	while (n > 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
		++i;
	}
	return (nbr);
}

static char	*ft_strrev(char *str, int len)
{
	int		i;
	char	t;

	i = 0;
	while (i < len / 2)
	{
		t = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = t;
		++i;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	long	nbr_1;
	int		len;
	int		sign;

	len = int_size(n);
	nbr = (char *)malloc(len + 1);
	if (nbr == NULL)
		return (NULL);
	sign = 1;
	nbr_1 = n;
	if (n < 0)
		sign *= -1;
	ft_fillnbr(nbr, nbr_1 * sign, 0);
	if (n < 0)
		nbr[len -1] = '-';
	return (ft_strrev(nbr, len));
}
