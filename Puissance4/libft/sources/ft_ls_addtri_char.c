/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_addtri_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:16:12 by abary             #+#    #+#             */
/*   Updated: 2016/02/10 13:37:24 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_addtri_char(N_LIST **alst, N_LIST *new)
{
	t_list *lst;
	t_list *tmp;

	lst = *alst;
	tmp = NULL;
	if (lst)
	{
		while (lst && ft_strcmp(lst->content, new->content) < 0)
		{
			tmp = lst;
			lst = lst->next;
		}
		new->next = lst;
		if (!tmp)
			*alst = new;
		else
			tmp->next = new;
	}
	else
		*alst = new;
}
