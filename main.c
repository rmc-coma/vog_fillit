/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:00:45 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/16 11:22:38 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int	***tetriminos;

	if (argc == 2)
		if (ft_validate_tetrifile(open(argv[1], O_RDONLY)))
		{
			tetriminos = ft_extract_tetriminos(open(argv[1], O_RDONLY),
								ft_file_len(open(argv[1], O_RDONLY)));
			return (ft_solve(tetriminos));
		}
	ft_putendl("error");
	return (1);
}
