/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:32:49 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/06 16:16:45 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	ft_canput(int **tetrimino, t_tetrimap *tmap, t_len i, t_len j)
{
	if (tetrimino[0][1] + i < tmap->tetrimap_size &&
		tetrimino[0][0] + j < tmap->tetrimap_size &&
		tetrimino[1][1] + i < tmap->tetrimap_size &&
		tetrimino[1][0] + j < tmap->tetrimap_size &&
		tetrimino[2][1] + i < tmap->tetrimap_size &&
		tetrimino[2][0] + j < tmap->tetrimap_size &&
		tetrimino[3][1] + i < tmap->tetrimap_size &&
		tetrimino[3][0] + j < tmap->tetrimap_size &&
		tmap->tetrimap[tetrimino[0][1] + i][tetrimino[0][0] + j] == '.' &&
		tmap->tetrimap[tetrimino[1][1] + i][tetrimino[1][0] + j] == '.' &&
		tmap->tetrimap[tetrimino[2][1] + i][tetrimino[2][0] + j] == '.' &&
		tmap->tetrimap[tetrimino[3][1] + i][tetrimino[3][0] + j] == '.')
	{
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	ft_place(int **tetrimino, t_tetrimap *tmap, char c)
{
	t_len	i;
	t_len	j;

	i = tmap->x_rdr;
	j = tmap->y_rdr;
	while (i < tmap->tetrimap_size)
	{
		j = (i == tmap->x_rdr && j == tmap->y_rdr) ? j : 0;
		while (j < tmap->tetrimap_size)
		{
			if (ft_canput(tetrimino, tmap, i, j))
			{
				tmap->tetrimap[tetrimino[0][1] + i][tetrimino[0][0] + j] = c;
				tmap->tetrimap[tetrimino[1][1] + i][tetrimino[1][0] + j] = c;
				tmap->tetrimap[tetrimino[2][1] + i][tetrimino[2][0] + j] = c;
				tmap->tetrimap[tetrimino[3][1] + i][tetrimino[3][0] + j] = c;
				tmap->x_rdr = 0;
				tmap->y_rdr = 0;
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

static void		ft_unplace(t_tetrimap *tmap, char c)
{
	t_len	block_count;
	t_len	i;
	t_len	j;

	block_count = 0;
	i = tmap->tetrimap_size;
	while (i > 0 && block_count != 4)
	{
		j = tmap->tetrimap_size;
		while (j > 0 && block_count != 4)
		{
			if (tmap->tetrimap[i - 1][j - 1] == c)
			{
				tmap->tetrimap[i - 1][j - 1] = '.';
				block_count++;
			}
			j--;
		}
		i--;
	}
	tmap->x_rdr = i;
	tmap->y_rdr = j;
}

static void		ft_increment_readers(t_tetrimap *tmap)
{
	tmap->y_rdr++;
	if (tmap->y_rdr == tmap->tetrimap_size - 1)
	{
		tmap->y_rdr = 0;
		tmap->x_rdr++;
	}
}

t_bool			ft_solve(int ***tetriminos)
{
	t_len		tetriminos_n;
	t_tetrimap	*tmap;
	t_len		i;

	tetriminos_n = ft_get_tetriminos_n(tetriminos);
	tmap = ft_create_tetrimap(2);
	i = 0;
	while (i < tetriminos_n)
	{
		if (!ft_place(tetriminos[i], tmap, i + 65))
		{
			if (i == 0)
				tmap = ft_upscale_tetrimap(tmap);
			else
			{
				i--;
				ft_unplace(tmap, i + 65);
				ft_increment_readers(tmap);
			}
		}
		else
			i++;
	}
	ft_puttetrimap(tmap);
	return (TRUE);
}
