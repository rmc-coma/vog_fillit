/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttetrimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:46:14 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/05 17:07:23 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puttetrimap(t_tetrimap *tmap)
{
	t_len	i;

	i = 0;
	while (i < tmap->tetrimap_size)
		ft_putstr(tmap->tetrimap[i++]);
}
