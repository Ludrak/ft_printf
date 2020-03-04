/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:56:37 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:50:32 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_c;
	size_t	size;

	size = 0;
	s_c = (char *)s;
	while (size < n)
	{
		if (s_c[size] == c)
			return (s_c + size);
		size++;
	}
	return (0);
}
