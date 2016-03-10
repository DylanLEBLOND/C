/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:58:34 by abary             #+#    #+#             */
/*   Updated: 2016/02/02 14:46:00 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_flag_0(char *format, int d, char *str)
{
	char *space;

	d = 0;
	space = str;
	while ((*str == ' ' || *str == '0'))
		*str++ = '0';
	if (*str == '+' && format)
	{
		*str = '0';
		*(str - (str - space)) = '+';
	}
	if (*str == 'x' && format)
	{
		*str = '0';
		*(str - (str - space - 1)) = 'x';
	}
	if (*str == '-' && format)
	{
		*str = '0';
		*(str - (str - space)) = '-';
	}
	return (str - (str - space));
}
