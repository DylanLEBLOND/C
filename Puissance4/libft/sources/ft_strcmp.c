/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:15:58 by abary             #+#    #+#             */
/*   Updated: 2015/12/01 12:46:57 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int comp;

	comp = 0;
	while (*s1)
	{
		comp = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (comp != 0)
			return (comp);
		s1++;
		s2++;
	}
	comp = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (comp);
}
