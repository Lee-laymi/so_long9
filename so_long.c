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


int	key_hook(int keycode, t_game *game)
{
    (void) game;
    int mx;
    int my;

    mx = game->dim.p.x;
    my = game->dim.p.y;

    if (keycode == 13 || keycode == 126)
        my = my - 1;
    if (keycode == 0 || keycode == 123)
        mx = mx - 1;
    if (keycode == 1 || keycode == 125)
        my = my + 1;
    if (keycode == 2 || keycode == 124)
        mx = mx + 1;
    if (keycode == 53)
        ft_freemap(game);

    check_wall(mx,my,game);
	//printf("Key code! %d x = %d y = %d\n", keycode, game->dim.p.x, game->dim.p.y);
   
	return (0);
}

void check_wall(int mx,int my,t_game *game)
{
    if (game->map.real_map[my][mx] == '1')
        return ;
    if (game->map.real_map[my][mx] == '0' || game->map.real_map[my][mx] == 'C')
    {
        if (game->map.real_map[my][mx] == 'C')
            game->c--;
        game->map.real_map[my][mx] = 'P';
        mlx_put_image_to_window(game->mlx, game->win, game->background, game->dim.p.x * 64, game->dim.p.y * 64);
       if (game->map.real_map[game->dim.p.y][game->dim.p.x] != 'E')
            game->map.real_map[game->dim.p.y][game->dim.p.x] = '0';
       else
           mlx_put_image_to_window(game->mlx, game->win, game->door, game->dim.p.x * 64, game->dim.p.y * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->background, mx * 64, my * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->player, mx * 64, my * 64);
        game->dim.p.x = mx;
        game->dim.p.y = my;
        game->walking++;
        ft_printf("walking = %d\n", game->walking);
    }

    if (game->map.real_map[my][mx] == 'E')
    {
        mlx_put_image_to_window(game->mlx, game->win, game->background, mx * 64, my * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->player, mx * 64, my * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->background, game->dim.p.x * 64, game->dim.p.y * 64);
        game->map.real_map[game->dim.p.y][game->dim.p.x] = '0';
        game->dim.p.x = mx;
        game->dim.p.y = my;
        game->walking++;
        ft_printf("walking = %d\n", game->walking);
        if (game->c == 0)
        {
            ft_freemap(game);
        } 

    }
}
// int	ft_keyhook(void)
// {
// 	t_game  game;

// 	game.mlx = mlx_init();
// 	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
//     //mlx_mouse_hook(game.win, mouse_hook, &game);

// 	mlx_loop(game.mlx);
//     return (0);
// }
int exit_hook(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    ft_freemap(game);
    return (0);

}
void ft_opengame(t_game *game)
{
    int w;
    int h;

    ft_initmlxenv(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->dim.size.x * 64, game->dim.size.y * 64, "So_Long");
	game->wall = mlx_xpm_file_to_image(game->mlx, "./texture/wall1.xpm", &w, &h);
    game->background = mlx_xpm_file_to_image(game->mlx, "./texture/background.xpm", &w, &h);
    game->collect = mlx_xpm_file_to_image(game->mlx, "./texture/ballon3.xpm", &w, &h);
    game->door = mlx_xpm_file_to_image(game->mlx, "./texture/door2.xpm", &w, &h);
    game->player = mlx_xpm_file_to_image(game->mlx, "./texture/player3.xpm", &w, &h);
    // mlx_put_image_to_window(game->mlx, game->win, game->wall, 0, 0);
    int y = 0;
    int x;

    while(y < game->dim.size.y)
    {
        x = 0;
        while (x < game->dim.size.x)
        {
            mlx_put_image_to_window(game->mlx, game->win, game->background, x * 64, y * 64);
            if (game->map.real_map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collect, x * 64, y * 64);
            if (game->map.real_map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->door, x * 64, y * 64);
            if (game->map.real_map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y * 64);
            if (game->map.real_map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player, x * 64, y * 64);
            x++;
        }
        y++;

    }
    mlx_key_hook(game->win, key_hook, game);
    mlx_hook(game->win, 17, 1L << 0, exit_hook, game);
    mlx_loop(game->mlx);
}

int main(int ac, char **av)
{
    int i;
    t_game  game;

    i = 0;
    ft_check_ac(ac, av);
    //ft_checkformat(av[1], &game);
    ft_initmap(&game);
    ft_initdim(&game);
    ft_create_tmpmap(av[1], &game);
    ft_create_realmap(av[1], &game);
    ft_checkmap(&game);
    ft_floodfillmap(&game);
    ft_opengame(&game);
}

