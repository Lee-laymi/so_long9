/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:17:09 by skrairab          #+#    #+#             */
/*   Updated: 2022/04/06 23:58:09 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clr;

	while (*lst != NULL)
	{
		clr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = clr;
	}
	*lst = 0;
}
