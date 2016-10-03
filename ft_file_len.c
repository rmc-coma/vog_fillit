/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:28:24 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/22 17:56:16 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_len	ft_file_len(int fd)
{
	char	c;
	t_len	file_len;

	c = 0;
	file_len = 0;
	while (read(fd, &c, 1) == 1)
		file_len++;
	close(fd);
	return (file_len);
}
