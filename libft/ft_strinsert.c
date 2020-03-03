/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:17:54 by lrobino           #+#    #+#             */
/*   Updated: 2020/03/02 18:38:07 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strinsert(char *src, char *in, size_t pos)
{
    char    *out;
    size_t  src_s;
    size_t  in_s;
    int     i;

    i = 0;
    in_s = ft_strlen(in);
    src_s = ft_strlen(src);
    if (pos > src_s || !(out = ft_calloc(src_s + ft_strlen(in) + 1, sizeof(char))))
        return (0);
    while (pos--)
        out[i++] = *src++;
    while (in_s--)
        out[i++] = *in++;
    while (*src)
        out[i++] = *src++;
    return (out);
}