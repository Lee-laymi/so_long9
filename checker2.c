/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:13:11 by skrairab          #+#    #+#             */
/*   Updated: 2023/02/22 11:57:03 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkwallx(t_game *game)
{
	int	k;

	k = 0;
	while (k < game->dim.size.x)
	{
		if (game->map.tmp_map[0][k] != '1'
			|| game->map.tmp_map[game->dim.size.y - 1][k] != '1')
		{
			write(2, "Map have no wall in x-direction%s\n", 31);
			return (0);
		}
		k++;
	}
	return (1);
}

int	ft_checkwally(t_game *game)
{
	int		j;

	j = 0;
	while (j < game->dim.size.y)
	{
		if (game->map.tmp_map[j][0] != '1'
		|| game->map.tmp_map[j][game->dim.size.x - 1] != '1')
		{
			write(2, "Map have no wall in y-direction%s\n", 31);
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_checkrec(t_game *game)
{
	int		j;
	int		len_rec;

	j = 0;
	while (j < game->dim.size.y)
	{
		len_rec = ft_lenx(game->map.tmp_map[j]);
		if (game->dim.size.x != len_rec)
		{
			write(2, "Map is not rectangula%s\n", 22);
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_lenx(char *str)
{
	int		len;

	len = 0;
	while (((str[len]) != '\n') && (str[len] != '\0'))
		len++;
	return (len);
}
