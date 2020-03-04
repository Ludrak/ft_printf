/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:38:39 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:51:23 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_c;

	s_c = (char *)s;
	while (*s_c)
	{
		if (*s_c == (char)c)
			return (s_c);
		s_c++;
	}
	if (*s_c == (char)c)
		return (s_c);
	return (0);
}
