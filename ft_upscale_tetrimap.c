/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upscale_tetrimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 17:43:25 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/04 21:12:59 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimap	*ft_upscale_tetrimap(t_tetrimap *tmap)
{
	t_len	old_size;
	t_len	i;

	old_size = tmap->tetrimap_size;
	i = 0;
	while (tmap->tetrimap[i][0])
		free(tmap->tetrimap[i++]);
	free(tmap->tetrimap);
	free(tmap);
	tmap = ft_create_tetrimap(old_size + 1);
	tmap->x_rdr = 0;
	tmap->y_rdr = 0;
	return (tmap);
}
