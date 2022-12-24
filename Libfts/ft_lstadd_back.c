/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:44:56 by skrairab          #+#    #+#             */
/*   Updated: 2022/04/07 22:12:15 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ab;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			ab = ft_lstlast(*lst);
			ab->next = new;
		}
		else
			*lst = new;
	}
}
