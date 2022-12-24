/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:08:58 by ami               #+#    #+#             */
/*   Updated: 2022/12/18 17:30:06 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_create_tmpmap(char *av, t_game *game)
{
	int		opened;
	int		j;

	ft_findxy(av, game);
    if (game->dim.size.y == 0)
	{
		write(2, "Map Error\n", 10);
		exit (0);
	}
	game->map.tmp_map = malloc(sizeof(char *) * (game->dim.size.y));
	opened = open(av, O_RDONLY);
	if (opened < 0)
		exit(0);
	j = 0;
	while (j < game->dim.size.y)
	{
		game->map.tmp_map[j] = get_next_line(opened);
		game->map.tmp_map[j][game->dim.size.x]  = '\0';
		j++;
	}
	close(opened);
	return (game->map.tmp_map);
}

char	**ft_create_realmap(char *av, t_game *game)
{
	int		opened;
	int		j;

    if (game->dim.size.x == 0)
	{
		write(2, "Map Error\n", 10);
		exit (0);
	}
	game->map.real_map = malloc(sizeof(char *) * (game->dim.size.x + 1));
	opened = open(av, O_RDONLY);
	if (opened < 0)
		exit(0);
	j = 0;
	while (j < game->dim.size.y)
	{
		game->map.real_map[j] = get_next_line(opened);
		game->map.real_map[j][game->dim.size.x]  = '\0';
		j++;
	}
	close(opened);
	return (game->map.real_map);
}

void	ft_freemap(t_game *game)
{
        int i;

	i = 0;
	while (i < game->dim.size.y)
	{
		free(game->map.tmp_map[i]);
		free(game->map.real_map[i]);
        i++;
	}
    free(game->map.tmp_map);
	free(game->map.real_map);
    exit(0);
}

void    ft_checkmap(t_game *game)
{
	if (ft_checkpec(game) != 1)
		{
			ft_freemap(game);
		}
	else if (ft_checkwallx(game) != 1)
		{
			ft_freemap(game);
		}
	else if (ft_checkwally(game) != 1)
		{
			ft_freemap(game);
		}
	else if (ft_checkrec(game) != 1)
		{
			ft_freemap(game);
		}
}