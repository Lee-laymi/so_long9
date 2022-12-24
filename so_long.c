/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:00:21 by ami               #+#    #+#             */
/*   Updated: 2022/12/22 23:00:22 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// void    print_maps(char **map)
// {
//     int i;

//     i = 0;
//     while (map[i])
//     {
//         printf("%s", map[i]);
//         i++;
//     }
// }
void ft_opengame(t_game *game)
{
    int w;
    int h;

   // ft_initmlxenv(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->dim.size.x * 64, game->dim.size.y * 64, "So_Long");
	game->wall = mlx_xpm_file_to_image(game->mlx, "./texture/wall1.xpm", &w, &h);
    game->robot = mlx_xpm_file_to_image(game->mlx, "./texture/robot1.xpm", &w, &h);
    game->collect = mlx_xpm_file_to_image(game->mlx, "./texture/ballon1.xpm", &w, &h);
    game->door = mlx_xpm_file_to_image(game->mlx, "./texture/door.xpm", &w, &h);
    // mlx_put_image_to_window(game->mlx, game->win, game->wall, 0, 0);
    int y = 0;
    int x;

    while(y < game->dim.size.y)
    {
        x = 0;
        while (x < game->dim.size.x)
        {
            mlx_put_image_to_window(game->mlx, game->win, game->robot, x * 64, y * 64);
            if (game->map.real_map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collect, x * 64, y * 64);
            if (game->map.real_map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->door, x * 64, y * 64);
            if (game->map.real_map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y * 64);
            x++;
        }
        y++;
    }
    // game->img[0] = "";
    // game->img = mlx_new_image(game->mlx, 1920, 1080);

	
	mlx_loop(game->mlx);
}

int main(int ac, char **av)
{
    int i;
    t_game  game;


    i = 0;
    ft_check_ac(ac, av);
    ft_initmap(&game);
    ft_initdim(&game);
    printf("Hello\n");
    printf("Hello\n");
    printf("Hello\n");
    ft_create_tmpmap(av[1], &game);
    // while (game.map.tmp_map[i])
    // {
    //     printf("|%s|", game.map.tmp_map[i]);
    //     i++;
    // }
    // i = 0;
    // printf("\n==============\n");
    ft_create_realmap(av[1], &game);
    // while (game.map.real_map[i])
    // {
    //     printf("|%s|", game.map.real_map[i]);
    //     i++;
    // }
    // ft_checkwallx(&game);
    // ft_checkwally(&game);
    // ft_checkrec(&game);
    // ft_checkpec(&game);
    ft_checkmap(&game);
    ft_floodfillmap(&game);
    ft_opengame(&game);

}

