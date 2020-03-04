/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:20:07 by plamtenz          #+#    #+#             */
/*   Updated: 2020/03/04 18:52:12 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_set(const char s1, const char *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

static int		ft_trimlen(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (check_set(s1[--end], set))
		;
	return (end);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	size_t		start;
	char		*res;

	start = -1;
	if (!s1)
		return (NULL);
	if (!ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	while (check_set(s1[++start], set))
		;
	if (!s1[start])
		return (ft_calloc(1, sizeof(char)));
	if (!(res = (ft_substr(s1, start, ft_trimlen(s1, set) - start + 1))))
		return (NULL);
	return (res);
}
