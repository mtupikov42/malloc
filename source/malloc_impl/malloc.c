/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 20:01:51 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/04 16:43:14 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "malloc_impl.h"
#include "blocks.h"
#include "globals.h"
#include "t_heap.h"
#include "helpers.h"

pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*malloc(size_t size)
{
	enum e_heap	type;
	t_block		*block;

	if (size == 0)
		return (NULL);
	pthread_mutex_lock(&g_mutex);
	size = ALIGN4(size);
	type = get_zone_type_from_block_size(size);
	block = allocate_block(type, size);
	pthread_mutex_unlock(&g_mutex);
	if (block)
		return (void *)((char *)block + AL_BLOCK_SIZE);
	return (NULL);
}
