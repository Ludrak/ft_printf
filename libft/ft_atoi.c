/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lrobino <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 21:34:07 by lrobino      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 16:18:20 by lrobino     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int			ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	num;
	unsigned long	max;

	sign = 1;
	num = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	max = sign < 0 ? 9223372036854775808UL : 9223372036854775807L;
	while (ft_isdigit(*nptr))
		num = (10 * num) + (*nptr++ - '0');
	if (num > max)
		return (sign < 0 ? 0 : -1);
	return (num * sign);
}
