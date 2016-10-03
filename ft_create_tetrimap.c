/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tetrimap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 17:36:40 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/04 20:53:50 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_reinitialize_readers(t_tetrimap *tmap)
{
	tmap->x_rdr = 0;
	tmap->y_rdr = 0;
}

t_tetrimap	*ft_create_tetrimap(t_len tetrimap_size)
{
	t_tetrimap	*tmap;
	t_len		i;
	t_len		j;

	tmap = (t_tetrimap *)malloc(sizeof(t_tetrimap));
	tmap->tetrimap = (char **)malloc(sizeof(char *) * (tetrimap_size + 1));
	tmap->tetrimap[tetrimap_size] = (char *)malloc(sizeof(char));
	tmap->tetrimap[tetrimap_size][0] = 0;
	tmap->tetrimap_size = tetrimap_size;
	i = 0;
	while (i < tmap->tetrimap_size)
	{
		j = 0;
		tmap->tetrimap[i] = (char *)malloc(sizeof(char) * (tetrimap_size + 2));
		tmap->tetrimap[i][tetrimap_size + 1] = 0;
		tmap->tetrimap[i][tetrimap_size] = '\n';
		while (j < tetrimap_size)
		{
			tmap->tetrimap[i][j] = '.';
			j++;
		}
		i++;
	}
	ft_reinitialize_readers(tmap);
	return (tmap);
}
