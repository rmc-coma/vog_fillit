/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:17:10 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/06 16:17:16 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	long long	n;
	char		s;

	while (*str && (*str == '\n' || *str == ' ' || *str == '\t' \
				|| *str == '\r' || *str == '\v' || *str == '\f'))
		str++;
	s = (*str == 45 ? 1 : 0);
	if (*str == 43 || *str == 45)
		str++;
	n = 0;
	while (*str)
	{
		if (*str > 47 && *str < 58)
			n = n * 10 + ((long long)(*str++) - 48);
		else
			break ;
	}
	return (s ? -n : n);
}
