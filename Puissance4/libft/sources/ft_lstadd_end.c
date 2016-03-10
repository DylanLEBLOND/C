/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:00:42 by abary             #+#    #+#             */
/*   Updated: 2015/12/02 14:20:02 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *lst;
	t_list *tmp;

	lst = *alst;
	if (lst)
	{
		tmp = lst;
		while (lst)
		{
			tmp = lst;
			lst = lst->next;
		}
		tmp->next = new;
	}
	else
		*alst = new;
}
