/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opened.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:51:01 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/22 16:34:37 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_findxy(char *av, t_game *game)
{
	int		opened;
	char	*str;
	int		i;

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
		exit(0) ;
	}
	game->dim.size.x = ft_lenx(str);
	i = 0;
	while (str)
	{
		free(str);
		str = get_next_line(opened);
		game->dim.size.y++;
	}
	free (str);
	close (opened);
}

void	ft_checkformat(char *av, t_game *game)
{
	int		opened;
	char	*str;
	int		i;

	opened = open(av, O_RDONLY);
	if (opened < 0)
	{
		write(2, "File not found\n", 15);
		return ;
	}
	str = get_next_line(opened);
	i = 0;
	while (str[i])
	{
		if (str[i] != '0' || str[i] != '1' || str[i] != 'P' || str[i] != 'C' || str[i] != 'E')
		{
			write(2, "Map error\n", 10);
			exit(0) ;
		}
	}
	i = 0;
	while (str)
	{
		free(str);
		printf("Hello!");
		str = get_next_line(opened);
		game->dim.size.y++;
	}
	free (str);
	close (opened);
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