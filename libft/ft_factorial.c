/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 20:19:36 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/18 17:58:02 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_factorial(unsigned long long n)
{
	if (n == 0)
		return (1);
	return (n == 1 ? n : n * ft_factorial(n - 1));
}
