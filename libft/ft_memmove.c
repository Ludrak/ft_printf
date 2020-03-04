/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:41:48 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:50:49 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;

	c_dst = (char *)dst;
	c_src = (char *)src;
	if (c_src >= c_dst)
		return (ft_memcpy(dst, src, len));
	c_dst += len;
	c_src += len;
	while (len--)
		*--c_dst = *--c_src;
	return (dst);
}
