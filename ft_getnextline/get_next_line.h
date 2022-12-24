/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:16:12 by skrairab          #+#    #+#             */
/*   Updated: 2022/12/14 16:21:14 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 512
#endif

typedef struct s_stash
{
	char	*buffer;
	char	*p;
	char	*nline;
	int		fd;
	int		readed;
	int		start;
}			t_stash;

char	*get_next_line(int fd);
size_t	ft_strleng(char *s, int mode);
char	*ft_strjoing(char *s1, char *s2);
char	*ft_strlcpyg(char *dst, char *src);
char	*ft_a(char *s);
int		ft_count(char *str, t_stash p);
void	struct_int(int fd, t_stash *p);
char	*ft_readed(int readed, char *getp, char *buff);
char	*ft_getp(int fd, char *getp, t_stash p);

#endif
