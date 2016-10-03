/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 13:58:18 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/05 17:06:25 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# include "libft/libft.h"

# define FALSE 0
# define TRUE !FALSE

typedef unsigned char	t_bool;
typedef unsigned int	t_len;
typedef struct			s_tetrimap
{
	char	**tetrimap;
	t_len	tetrimap_size;
	t_len	x_rdr;
	t_len	y_rdr;
}						t_tetrimap;

t_bool					ft_validate_tetrifile(int fd);
t_len					ft_file_len(int fd);
int						***ft_extract_tetriminos(int fd, t_len file_len);
t_len					**ft_combinate(t_len n);
t_bool					ft_solve(int ***tetriminos);
void					ft_puttetrimap(t_tetrimap *tetrimap);
t_tetrimap				*ft_create_tetrimap(t_len tetrimap_size);
t_tetrimap				*ft_upscale_tetrimap(t_tetrimap *tmap);
t_len					ft_get_tetriminos_n(int ***tetriminos);

#endif
