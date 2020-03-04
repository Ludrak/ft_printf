/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:14:17 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:50:36 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (uc_s1[count] != uc_s2[count])
			return (uc_s1[count] - uc_s2[count]);
		count++;
	}
	return (0);
}
