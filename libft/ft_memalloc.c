/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 12:24:32 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:20:14 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(const size_t size)
{
	void *ret;

	if (!(ret = malloc(size)))
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
