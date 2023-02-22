/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:13:38 by skrairab          #+#    #+#             */
/*   Updated: 2023/02/22 11:56:52 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_ac(int ac, char **av)
{
	char	*check_path;

	if (ac < 2)
	{
		write(2, "agument is not enought %s\n", 21);
		exit (0);
	}
	else if (ac > 2)
	{
		write(2, "agument is too much %s\n", 19);
		exit (0);
	}
	check_path = ft_strnstr(&av[1][ft_strlen(av[1]) - 4], ".ber", 4);
	if (check_path == NULL)
	{
		write(2, "File name is incorrect. Please try again!. %s\n", 42);
		exit (0);
	}
}

int	ft_countpec(t_game *game, int mode)
{
	int		count;

	count = 0;
	game->j = 0;
	while (game->j < game->dim.size.y)
	{
		game->k = 0;
		while (game->k < game->dim.size.x)
		{
			if ((mode == 1) && (game->map.tmp_map[game->j][game->k] == 'P'))
				count++;
			else if ((mode == 2)
				&& (game->map.tmp_map[game->j][game->k] == 'E'))
				count++;
			else if ((mode == 3)
				&& (game->map.tmp_map[game->j][game->k] == 'C'))
			{
				count++;
				game->c = count;
			}
			game->k++;
		}
		game->j++;
	}
	return (count);
}

int	ft_checkpec(t_game *game)
{
	if (ft_countpec(game, 1) != 1)
	{
		write(2, "Player is error%s\n", 16);
		ft_freemap(game);
	}
	else if (ft_countpec(game, 2) != 1)
	{
		write(2, "Exit is error%s\n", 14);
		ft_freemap(game);
	}
	else if (ft_countpec(game, 3) < 1)
	{
		write(2, "Collectable is error%s\n", 21);
		ft_freemap(game);
	}
	return (1);
}
