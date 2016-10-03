/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos_n.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:50:25 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/05 16:43:26 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_len	ft_get_tetriminos_n(int ***tetriminos)
{
	t_len	i;

	i = 0;
	while (tetriminos[i] != NULL)
		i++;
	return (i);
}
