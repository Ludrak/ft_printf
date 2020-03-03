/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lrobino <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 20:52:21 by lrobino      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 16:23:00 by lrobino     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	i = -1;
	if (!(ret = malloc((ft_strlen(str) + 1) * sizeof(*ret))))
		return (0);
	while (str[++i])
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}
