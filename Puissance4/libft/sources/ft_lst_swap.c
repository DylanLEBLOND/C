/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:09:17 by abary             #+#    #+#             */
/*   Updated: 2016/02/09 15:13:48 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_swap(N_LIST **e_lst1, N_LIST **e_lst2, N_LIST **pre)
{
	N_LIST	*lst1;
	N_LIST	*lst2;

	if (e_lst1 && e_lst2)
	{
		lst1 = *e_lst1;
		lst2 = (*e_lst2)->next;
		*e_lst1 = *e_lst2;
		*e_lst2 = lst1;
		(*e_lst1)->next = *e_lst2;
		(*e_lst2)->next = lst2;
		if (*pre)
			(*pre)->next = *e_lst1;
	}
}
