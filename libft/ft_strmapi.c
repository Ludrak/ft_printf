/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:37:35 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:51:56 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (!(new = malloc((ft_strlen(s) + 1) * sizeof(*new))))
		return (0);
	while (s[++i])
		new[i] = f(i, s[i]);
	new[i] = 0;
	return (new);
}
