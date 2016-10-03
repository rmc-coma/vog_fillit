/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_tetrifile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:26 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/16 11:18:00 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	ft_validate_shape(char *buffer)
{
	t_len	i;
	t_len	j;

	i = 20;
	j = 0;
	if (buffer[4] != '\n' || buffer[9] != '\n' ||
		buffer[14] != '\n' || buffer[19] != '\n')
		return (FALSE);
	while (i-- && j < 3)
	{
		if (*buffer == '#')
		{
			j++;
			if (*(buffer + 1) != '#' && *(buffer + 5) != '#')
				if ((j == 1) ||
					(!((j == 2 || j == 3) &&
					*(buffer - 1) == '#' && *(buffer + 4) == '#') &&
					!(j == 3 &&
					*(buffer - 1) == '#' && *(buffer - 2) == '#' &&
					*(buffer + 3) == '#')))
					return (FALSE);
		}
		buffer++;
	}
	return (TRUE);
}

static t_bool	ft_vld_chars(char *buffer)
{
	t_len	block_n;
	t_len	dot_n;
	t_len	cr_n;
	t_len	i;

	block_n = 0;
	dot_n = 0;
	cr_n = 0;
	i = 20;
	if (buffer[0] == '\n')
		return (FALSE);
	while (i--)
	{
		if (buffer[i] == '.')
			dot_n++;
		else if (buffer[i] == '\n')
			cr_n++;
		else if (buffer[i] == '#')
			block_n++;
		else
			return (FALSE);
	}
	if (block_n != 4 || dot_n != 12 || cr_n != 4)
		return (FALSE);
	return (TRUE);
}

static t_bool	ft_quit(int fd)
{
	close(fd);
	return (FALSE);
}

static void		ft_read(int fd, char *buffer, t_len *read_c)
{
	ft_bzero(buffer, 22);
	*read_c = (t_len)read(fd, buffer, 20);
	read(fd, &buffer[20], 1);
}

t_bool			ft_validate_tetrifile(int fd)
{
	char	buffer[22];
	t_len	read_c;
	t_len	i;
	t_bool	eof;

	read_c = 0;
	i = 0;
	eof = FALSE;
	while (!eof)
	{
		ft_read(fd, buffer, &read_c);
		if (buffer[20] == 0)
			eof = TRUE;
		else if (buffer[20] == '\n')
			buffer[20] = 0;
		else
			return (ft_quit(fd));
		if (read_c < 20 || !ft_vld_chars(buffer) || !ft_validate_shape(buffer))
			return (ft_quit(fd));
		i++;
	}
	if (read(fd, buffer, 1))
		i = 0;
	close(fd);
	return (i >= 1 && i <= 26 ? TRUE : FALSE);
}
