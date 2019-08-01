/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 20:01:51 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/01 20:03:23 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free(void *ptr)
{
	(void)ptr;
}

void	*malloc(size_t size)
{
	(void)size;
	return (NULL);
}

void	*realloc(void *ptr, size_t size)
{
	(void)ptr;
	(void)size;
	return (NULL);
}
