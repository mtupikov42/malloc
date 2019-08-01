/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:34:42 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:32:40 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_tolower(const int c)
{
	unsigned char uc;

	if (!ft_isascii(c))
		return (c);
	uc = (unsigned char)c;
	if (c >= 'A' && c <= 'Z')
		return ((int)uc + 32);
	return (c);
}
