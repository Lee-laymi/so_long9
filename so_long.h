/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:00:37 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/22 17:39:46 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./Libfts/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "math.h"
# include "ft_getnextline/get_next_line.h"
# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"

typedef struct s_vector
{
    int     x;
    int     y;

}           t_vec;


typedef struct s_map
{
    char    *path;
    char    **real_map;
    char    **tmp_map;
    
}               t_map;

typedef struct s_dim
{
    t_vec   size;
    t_vec   p;

}               t_dim;

typedef struct s_game
{
    t_dim   dim;
    t_map   map;
    void	*mlx;
	void	*win;
	void	*wall;
    void    *player;
    void    *floor;
    void    *collect;
    void    *door;
    void    *background;
    int     c;
    int     walking;

}               t_game;


void	ft_findxy(char *av, t_game *game);
int		ft_countpec(t_game *game, int mode);
int		ft_checkwallx(t_game *game);
int		ft_checkwally(t_game *game);
int		ft_checkrec(t_game *game);
int		ft_lenx(char *str);
char	**ft_create_tmpmap(char *av, t_game *game);
void	    ft_floodfill(t_game *game, int x, int y);
int		check_floodfill(t_game *game);
void	ft_check_ac(int ac, char **av);
void	ft_freemap(t_game *game);
int	    ft_checkpec(t_game *game);
void    ft_checkmap(t_game *game);
void	ft_findp(t_game *game);
void     ft_floodfillmap(t_game *game);
char	**ft_create_realmap(char *av, t_game *game);
void	ft_initmap(t_game *game);
void	ft_initdim(t_game *game);
void ft_opengame(t_game *game);
void	ft_initmlxenv(t_game *game);
int	ft_keyhook(void);
int	key_hook(int keycode, t_game *s_game);
void check_wall(int mx,int my,t_game *game);
int exit_hook(t_game *game);
void	ft_checkformat(char *av, t_game *game);

#endif