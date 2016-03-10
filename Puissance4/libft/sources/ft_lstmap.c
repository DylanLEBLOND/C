/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:31:32 by abary             #+#    #+#             */
/*   Updated: 2015/12/02 14:13:29 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *beginmap;

	beginmap = NULL;
	while (lst)
	{
		map = (t_list*)malloc(sizeof(t_list));
		if (!map)
			return (NULL);
		if (f)
		{
			map = f(lst);
			ft_lstadd_end(&beginmap, map);
			lst = lst->next;
		}
	}
	return (beginmap);
}
