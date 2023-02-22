/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opened.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:29:00 by skrairab          #+#    #+#             */
/*   Updated: 2023/02/22 11:58:09 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_findxy(char *av, t_game *game)
{
	int		opened;
	char	*str;

	opened = open(av, O_RDONLY);
	if (opened < 0)
	{
		write(2, "File not found\n", 15);
		return ;
	}
	str = get_next_line(opened);
	if (str == 0)
	{
		write(2, "File error\n", 11);
		exit(0);
	}
	game->dim.size.x = ft_lenx(str);
	while (str)
	{
		free(str);
		str = get_next_line(opened);
		game->dim.size.y++;
	}
	free (str);
	close (opened);
}

void	ft_checkformat(t_game *game)
{
	int		n;
	int		m;

	n = 0;
	while (game->map.tmp_map[n] != NULL)
	{
		m = 0;
		while (game->map.tmp_map[n][m] && game->map.tmp_map[n][m] != '\n')
		{
			if (game->map.tmp_map[n][m] != '0' && game->map.tmp_map[n][m] != '1'
			&& game->map.tmp_map[n][m] != 'P' && game->map.tmp_map[n][m] != 'C'
			&& game->map.tmp_map[n][m] != 'E')
			{
				write(2, "Map error\n", 10);
				exit(0);
			}
			m++;
		}
		n++;
	}
}

void	ft_initmap(t_game *game)
{
	game->map.path = NULL;
	game->map.tmp_map = NULL;
	game->map.real_map = NULL;
}

void	ft_initdim(t_game *game)
{
	game->dim.size.x = 0;
	game->dim.size.y = 0;
	game->dim.p.x = 0;
	game->dim.p.y = 0;
	game->walking = 0;
	game->c = 0;
	game->i = 0;
	game->j = 0;
	game->k = 0;
	game->ax = 0;
	game->by = 0;
}

void	ft_initmlxenv(t_game *game)
{
	game->wall = NULL;
	game->player = NULL;
	game->floor = NULL;
	game->collect = NULL;
	game->door = NULL;
	game->background = NULL;
}
