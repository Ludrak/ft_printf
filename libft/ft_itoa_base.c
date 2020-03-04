/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:50:20 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:49:03 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_base(unsigned int n, char *base)
{
	int		i;

	i = 1;
	while (n /= ft_strlen(base))
		i++;
	return (i);
}

char			*ft_itoa_base(int n, char *base)
{
	char			*result;
	int				i;
	unsigned int	nb;

	nb = (unsigned long)n;
	i = ft_count_base(nb, base);
	if (!(result = ft_calloc((ft_count_base(n, base) + 1), sizeof(*result))))
		return (0);
	if (n == 0)
	{
		result[0] = base[0];
		return (result);
	}
	while (nb)
	{
		result[--i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	return (result);
}
