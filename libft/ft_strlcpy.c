/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lrobino <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 21:41:00 by lrobino      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 16:27:34 by lrobino     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	if (!(src && dst))
		return (0);
	src_len = ft_strlen(src);
	while (dstsize)
	{
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = 0;
	}
	return (src_len);
}
