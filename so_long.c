/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:11:53 by skrairab          #+#    #+#             */
/*   Updated: 2023/02/14 15:19:54 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walk(int mx, int my, t_game *game)
{
	if (game->map.real_map[my][mx] == '1')
		return ;
	if (game->map.real_map[my][mx] == '0' || game->map.real_map[my][mx] == 'C')
	{
		if (game->map.real_map[my][mx] == 'C')
			game->c--;
		game->map.real_map[my][mx] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->background,
			game->dim.p.x * 64, game->dim.p.y * 64);
		if (game->map.real_map[game->dim.p.y][game->dim.p.x] != 'E')
			game->map.real_map[game->dim.p.y][game->dim.p.x] = '0';
		else
			mlx_put_image_to_window(game->mlx, game->win, game->door,
				game->dim.p.x * 64, game->dim.p.y * 64);
		mlx_put_image_to_window(game->mlx, game->win,
			game->background, mx * 64, my * 64);
		mlx_put_image_to_window(game->mlx,
			game->win, game->player, mx * 64, my * 64);
		game->dim.p.x = mx;
		game->dim.p.y = my;
		game->walking++;
		ft_printf("walking = %d\n", game->walking);
	}
	ft_exit(mx, my, game);
}

void	ft_exit(int mx, int my, t_game *game)
{
	if (game->map.real_map[my][mx] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->background, mx * 64, my * 64);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, mx * 64, my * 64);
		mlx_put_image_to_window(game->mlx, game->win,
			game->background, game->dim.p.x * 64,
			game->dim.p.y * 64);
		game->map.real_map[game->dim.p.y][game->dim.p.x] = '0';
		game->dim.p.x = mx;
		game->dim.p.y = my;
		game->walking++;
		ft_printf("walking = %d\n", game->walking);
		if (game->c == 0)
			ft_freemap(game);
	}
}

void	ft_opengame(t_game *game)
{
	ft_initmlxenv(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->dim.size.x * 64, \
		game->dim.size.y * 64, "So_Long");
	ft_imgadd(game);
	ft_putimg(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 1L << 0, exit_hook, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	int		i;
	t_game	game;

	i = 0;
	ft_check_ac(ac, av);
	ft_initmap(&game);
	ft_initdim(&game);
	ft_create_tmpmap(av[1], &game);
	ft_checkformat(&game);
	ft_create_realmap(av[1], &game);
	ft_checkmap(&game);
	ft_floodfillmap(&game);
	ft_opengame(&game);
}
