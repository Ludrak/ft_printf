/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lrobino <lrobino@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 16:50:58 by lrobino      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 16:51:06 by lrobino     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	i = 0;
	while (i < n && (i == 0 || src_c[i - 1] != (unsigned char)c))
	{
		dst_c[i] = (unsigned char)src_c[i];
		i++;
	}
	if (i > 0 && src_c[i - 1] == c)
		return (dst_c + i);
	else
		return (0);
}
