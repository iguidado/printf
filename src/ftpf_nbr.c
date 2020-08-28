/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <iguidado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:26:32 by iguidado          #+#    #+#             */
/*   Updated: 2020/04/09 16:26:34 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_i(int nbr, t_format *fmt)
{
	int count;
	int pref;

	count = 0;
	pref = 0;
	fmt->preci = ftpf_ruler_i(nbr, fmt->preci);
	count += ftpf_padding_left(*fmt);
	if (nbr || fmt->preci)
	{
		if (nbr < 0)
		{
			count += write(1, "-", 1);
			pref++;
		}
		count += ftpf_padding_0(*fmt);
		count += ftpf_putf_i(nbr, fmt->preci - pref);
	}
	count += ftpf_padding_right(*fmt);
	return (count);
}

int	ftpf_u(unsigned int nbr, t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = ftpf_ruler_u(nbr, fmt->preci);
	count += ftpf_padding_left(*fmt);
	if (nbr || fmt->preci)
	{
		count += ftpf_padding_0(*fmt);
		count += ftpf_putf_u(nbr, fmt->preci);
	}
	count += ftpf_padding_right(*fmt);
	return (count);
}

int	ftpf_x(unsigned int nbr, t_format *fmt)
{
	int count;

	count = 0;
	fmt->preci = ftpf_ruler_x(nbr, fmt->preci);
	count += ftpf_padding_left(*fmt);
	if (nbr || fmt->preci)
	{
		count += ftpf_padding_0(*fmt);
		if (fmt->type == 'x')
			count += ftpf_putf_x(nbr, fmt->preci);
		else
			count += ftpf_putf_hex(nbr, fmt->preci);
	}
	count += ftpf_padding_right(*fmt);
	return (count);
}
