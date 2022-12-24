/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:11:28 by ami               #+#    #+#             */
/*   Updated: 2022/12/18 15:44:35 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

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
	int		k;
	int		j;
	int		c;
	int		i;

	i = 0;
	j = 0;
	c = 0;
	while (j < game->dim.size.y)
	{
		k = 0;
		while (k < game->dim.size.x)
		{
			if ((mode == 1) && (game->map.tmp_map[j][k] == 'P'))
				c++;
			else if ((mode == 2) && (game->map.tmp_map[j][k] == 'E'))
				c++;
			else if ((mode == 3) && (game->map.tmp_map[j][k] == 'C'))
			{
					c++;
					game->c = c;
			}
			k++;
		}
		j++;
	}
	return (c);
}

int	ft_checkpec(t_game *game)
{
    if (ft_countpec(game, 1) != 1 )
	{
		write(2, "Player is error%s\n", 16);
        ft_freemap(game);
	}
	if (ft_countpec(game, 2) != 1 )
	{
		write(2, "Exit is error%s\n", 14);
        ft_freemap(game);
	}
	if (ft_countpec(game, 3) < 1 )
    {
		write(2, "Collectable is error%s\n", 21);
        ft_freemap(game);
	}
    return (1);
}
