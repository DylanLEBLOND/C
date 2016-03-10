/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 15:19:31 by abary             #+#    #+#             */
/*   Updated: 2015/12/27 17:00:28 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static void		ft_clean_first(t_list **begin)
{
	t_list *next;

	next = (*begin)->next;
	if ((*begin)->content == NULL)
	{
		free(*begin);
		*begin = next;
	}
}

void			ft_lstclean(t_list **begin)
{
	t_list	*lst;
	t_list	*last;
	t_list	*next;

	ft_clean_first(begin);
	lst = *begin;
	while (lst)
	{
		last = lst;
		lst = lst->next;
		if (lst && lst->content == NULL)
		{
			next = lst->next;
			free(lst);
			last->next = next;
			lst = NULL;
			ft_lstclean(begin);
		}
	}
}
