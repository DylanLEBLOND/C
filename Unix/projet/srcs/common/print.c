/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <dle-blon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:14 by dle-blon          #+#    #+#             */
/*   Updated: 2016/09/30 15:17:47 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <function.h>

void	print_message (char *mess, char *filename)
{
	FILE *file;
	int res;

	if (filename == NULL)
	{
		printf ("%s", mess);
		return ;
	}

	file = NULL;
	file = fopen (filename, "a");
	if (file == NULL)
		fatal_error ("fopen failed");

	res = fputs (mess, file);
	fclose (file);

	if (res < 0)
		fatal_error ("fputs failed");
}

void	ft_putstr (char const *s, int eol)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			write (1, &s[i++], 1);
		if (eol)
			write (1, "\n", 1);
	}
}

void	ft_putstr_fd (char const *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			write (fd, &s[i++], 1);
	}
}
