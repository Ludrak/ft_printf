/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:15:34 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/04 18:51:38 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*new))))
		return (0);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcpy(new + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (new);
}
