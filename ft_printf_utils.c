/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:26:47 by arowe             #+#    #+#             */
/*   Updated: 2021/10/26 17:26:59 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t ft_printc(int c)
{
    char ch;

    ch = (char)c;
    write(1, &ch, 1);
    return (1);
}

size_t ft_prints(char *s)
{
    if (!s)
        return (ft_printf("(null)"));
    write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}

size_t ft_printp(unsigned long p)
{
	size_t	 len;
    char *hex;

	if (p == 0)
		return (ft_printf("(nil)"));
    hex = ft_dec_to_hex(p, 'p');
	len = ft_printf("0x%s", hex);
    free(hex);
    return (len);
}
size_t	ft_printdi(int d)
{
	char	nb_str[10];
	size_t 	len;

	if (d < 0)
		write(1, "-", 1);
	len = num_to_str(d, nb_str);
	write(1, nb_str, len);
	if (d < 0)
		return (len + 1);
	return (len);
}

size_t	ft_printu(unsigned int d)
{
	char	nb_str[10];
	size_t 	len;

	len = ft_u_to_str(d, nb_str);
	write(1, nb_str, len);
	return (len);
}

size_t ft_printx(unsigned int p, char flag)
{
	size_t	 len;
	char *hex;

	if (p == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex = ft_dec_to_hex(p, flag);
	len = ft_strlen(hex);
	write(1, hex, len);
	free(hex);
	return (len);
}