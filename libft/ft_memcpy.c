/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:01:35 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:22:26 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *restrict destptr, const void *restrict srcptr,
		size_t num)
{
	char		*dest;
	const char	*src;

	src = (const char *)srcptr;
	dest = (char *)destptr;
	while (num > 0)
	{
		*(dest++) = *(src++);
		num--;
	}
	return (destptr);
}
