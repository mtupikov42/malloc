/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:07:39 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:45:19 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *restrict memptr, const int val, size_t num)
{
	const unsigned char *mem;

	mem = memptr;
	while (num--)
		if (*mem++ == (unsigned char)val)
			return ((void *)--mem);
	return (NULL);
}
