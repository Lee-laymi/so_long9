/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:29:22 by skrairab          #+#    #+#             */
/*   Updated: 2023/02/22 11:58:17 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->dim.size.x || y >= game->dim.size.y
		|| game->map.tmp_map[y][x] == '1' || game->map.tmp_map[y][x] == 'W')
		return ;
	game->map.tmp_map[y][x] = 'W';
	ft_floodfill(game, x, y - 1);
	ft_floodfill(game, x + 1, y);
	ft_floodfill(game, x - 1, y);
	ft_floodfill(game, x, y + 1);
	return ;
}

void	ft_findp(t_game *game)
{
	game->dim.p.y = 0;
	while (game->map.tmp_map[game->dim.p.y])
	{
		game->dim.p.x = 0;
		while (game->map.tmp_map[game->dim.p.y][game->dim.p.x])
		{
			if (game->map.tmp_map[game->dim.p.y][game->dim.p.x] == 'P')
				return ;
			game->dim.p.x++;
		}
		game->dim.p.y++;
	}
}

int	check_floodfill(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->dim.size.y)
	{
		x = 0;
		while (x < game->dim.size.x)
		{
			if (game->map.tmp_map[y][x] == 'C'
				|| game->map.tmp_map[y][x] == 'P'
				|| game->map.tmp_map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_floodfillmap(t_game *game)
{
	ft_findp(game);
	ft_floodfill(game, game->dim.p.x, game->dim.p.y);
	if (check_floodfill(game) == 1)
	{
		write(2, "Map is incorrect. Please try again!. %s\n", 38);
		ft_freemap(game);
		exit (0);
	}
}
