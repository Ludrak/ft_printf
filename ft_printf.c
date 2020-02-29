/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lrobino <lrobino@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 23:35:44 by lrobino      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 00:48:15 by lrobino     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>
#include <limits.h>

static t_pf_data	pf_parse(char *format, va_list args)
{
	t_pf_data	data;
	t_flags		flags;
	char		*init_format;

	init_format = format;
	format += pf_parse_flags(format, &flags);
	data.flags = flags;
	pf_parse_padding(format, &data, args);
	pf_parse_precision(format, &data, args);
	pf_parse_content(format, &data, args);
	pf_set_flags(&data);
	pf_set_precision(&data);
	pf_set_padding(&data);
	data.f_len = pf_get_format_type(init_format, NULL);
	return (data);
}

int					ft_printf(char *format, ...)
{
	t_pf_data	data;
	va_list		args;
	int			length;

	va_start(args, format);
	length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			data = pf_parse(++format, args);
			length += data.len;
			write(1, data.content, data.len);
			format += data.f_len;
			free(data.content);
		}
		else if (*format)
		{
			write(1, format, 1);
			format++;
			length++;
		}
	}
	va_end(args);
	return (length);
}

// int main ()
// {
// 	ft_printf("%0+8.5i", 34);
// 	printf("\n%0+8.5i", 34);
// }
