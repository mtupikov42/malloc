/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:33:36 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:28:16 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *from, const size_t size)
{
	size_t dest_size;
	size_t from_size;
	size_t i;

	dest_size = ft_strlen(dest);
	from_size = ft_strlen(from);
	if (size <= dest_size)
		return (from_size + size);
	i = 0;
	while (from[i] && i + dest_size < size - 1)
	{
		dest[i + dest_size] = from[i];
		i++;
	}
	dest[i + dest_size] = '\0';
	return (dest_size + from_size);
}
