/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:33:45 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:44:45 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *restrict destptr,
		const void *restrict srcptr, const int c, size_t n)
{
	char		*dest;
	const char	*src;

	dest = (char *)destptr;
	src = (const char *)srcptr;
	if (n)
		while (n--)
			if ((*dest++ = *src++) == (char)c)
				return ((void *)dest);
	return (NULL);
}
