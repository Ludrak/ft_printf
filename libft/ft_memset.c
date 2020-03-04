/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:02:47 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:50:53 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str + n;
	while (n > 0)
	{
		n--;
		tmp--;
		*tmp = c;
	}
	return (str);
}
