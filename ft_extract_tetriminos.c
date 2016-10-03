/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_tetriminos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:58:45 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/12 17:14:03 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_init_vars(int *x, int *y, t_len *i, t_len *j)
{
	*x = 0;
	*y = 0;
	*i = 0;
	*j = 0;
}

static void	ft_torelative(int **tetriarray)
{
	tetriarray[3][0] -= tetriarray[0][0];
	tetriarray[3][1] -= tetriarray[0][1];
	tetriarray[2][0] -= tetriarray[0][0];
	tetriarray[2][1] -= tetriarray[0][1];
	tetriarray[1][0] -= tetriarray[0][0];
	tetriarray[1][1] -= tetriarray[0][1];
	tetriarray[0][0] -= tetriarray[0][0];
	tetriarray[0][1] -= tetriarray[0][1];
}

static int	**ft_fill_tetriarray(int **tetriarray, char *tetrimino)
{
	int		x;
	int		y;
	t_len	i;
	t_len	j;

	ft_init_vars(&x, &y, &i, &j);
	while (j < 20)
	{
		if (tetrimino[j] == '#')
		{
			tetriarray[i][0] = x;
			tetriarray[i][1] = y;
			i++;
		}
		if (++x == 4)
		{
			x = 0;
			y++;
			j++;
		}
		j++;
	}
	ft_torelative(tetriarray);
	return (tetriarray);
}

int			***ft_extract_tetriminos(int fd, t_len file_len)
{
	t_len	tetriminos_n;
	int		***tetriminos;
	t_len	i;
	t_len	j;
	char	tetrimino_buffer[21];

	tetriminos_n = (file_len + 1) / 21;
	tetriminos = (int ***)malloc(sizeof(int **) * (tetriminos_n + 1));
	tetriminos[tetriminos_n] = NULL;
	i = 0;
	while (i < tetriminos_n)
	{
		tetriminos[i] = (int **)malloc(sizeof(int *) * 4);
		j = 0;
		while (j < 4)
			tetriminos[i][j++] = (int *)malloc(sizeof(t_len) * 2);
		read(fd, tetrimino_buffer, 21);
		tetriminos[i] = ft_fill_tetriarray(tetriminos[i], tetrimino_buffer);
		i++;
	}
	close(fd);
	return (tetriminos);
}
