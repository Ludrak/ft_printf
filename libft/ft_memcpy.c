/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memcpy.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lrobino <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:15:51 by lrobino      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 16:21:29 by lrobino     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned int	i;

	i = 0;
	tmp = (unsigned char *)dst;
	if (dst == src || !n)
		return (dst);
	while (i < (unsigned int)n)
	{
		*tmp = *(unsigned char *)(src + i);
		tmp++;
		i++;
	}
	return (dst);
}
