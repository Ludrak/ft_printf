/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lrobino <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/03 19:23:25 by lrobino      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 22:01:57 by lrobino     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_get_next_len(char *s, char c)
{
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	while (*s && *s++ != c)
		n++;
	return ((n == 0) ? 1 : n);
}

static size_t		ft_getwords(char *s, char c)
{
	size_t	n;

	n = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			n++;
			while (*s && *s != c)
				s++;
		}
	}
	return ((n == 0) ? 1 : n);
}

static void			*ft_free(char **ret, int pos)
{
	while (pos--)
		free(ret[pos]);
	free(ret);
	return (0);
}

char				**ft_split(const char *str, char c)
{
	char	**ret;
	size_t	next_len;
	size_t	i;
	char	*s;

	if (!(s = (char *)str))
		return (ft_calloc(1, 1));
	if (!(ret = ft_calloc(sizeof(*ret), ft_getwords((char *)s, c) + 1)))
		return (0);
	i = 0;
	while (*s)
	{
		while (s && *s == c)
			s++;
		if (*s)
		{
			next_len = ft_get_next_len((char *)s, c);
			if (!(ret[i] = ft_calloc(sizeof(char), (next_len + 1))))
				return (ft_free(ret, i));
			ft_memcpy(ret[i], s, next_len);
			ret[i++][next_len] = '\0';
			s += next_len;
		}
	}
	return (ret);
}
