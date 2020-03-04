/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:06:10 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 19:00:34 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int				sign;
	char			*result;
	int				i;
	unsigned int	nb;

	nb = (n < 0) ? -n : n;
	sign = n < 0;
	i = ft_count(n) + sign;
	if (!(result = ft_calloc((ft_count(n) + 1 + sign), sizeof(*result))))
		return (0);
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	result[0] = '-';
	while (nb)
	{
		result[--i] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}
