/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:28:39 by skrairab          #+#    #+#             */
/*   Updated: 2023/02/22 11:58:02 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	mx;
	int	my;

	mx = game->dim.p.x;
	my = game->dim.p.y;
	if (keycode == 13 || keycode == 126)
		my = my - 1;
	else if (keycode == 0 || keycode == 123)
		mx = mx - 1;
	else if (keycode == 1 || keycode == 125)
		my = my + 1;
	else if (keycode == 2 || keycode == 124)
		mx = mx + 1;
	else if (keycode == 53)
		ft_freemap(game);
	else
		return (0);
	check_walk(mx, my, game);
	return (0);
}

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_freemap(game);
	return (0);
}

void	ft_imgadd(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./texture/wall1.xpm", &w, &h);
	game->background = mlx_xpm_file_to_image(game->mlx,
			"./texture/background.xpm", &w, &h);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"./texture/ballon3.xpm", &w, &h);
	game->door = mlx_xpm_file_to_image(game->mlx,
			"./texture/door2.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./texture/player3.xpm", &w, &h);
}

void	ft_putimg(t_game *game)
{
	while (game->by < game->dim.size.y)
	{
		game->ax = 0;
		while (game->ax < game->dim.size.x)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->background, game->ax * 64, game->by * 64);
			if (game->map.real_map[game->by][game->ax] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->win, game->collect, game->ax * 64, game->by * 64);
			else if (game->map.real_map[game->by][game->ax] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->win, game->door, game->ax * 64, game->by * 64);
			else if (game->map.real_map[game->by][game->ax] == '1')
				mlx_put_image_to_window(game->mlx,
					game->win, game->wall, game->ax * 64, game->by * 64);
			else if (game->map.real_map[game->by][game->ax] == 'P')
				mlx_put_image_to_window(game->mlx,
					game->win, game->player, game->ax * 64, game->by * 64);
			game->ax++;
		}
		game->by++;
	}
}
