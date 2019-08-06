/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:24:46 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/06 21:15:33 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "blocks.h"
#include "globals.h"
#include "t_heap.h"
#include "helpers.h"
#include <sys/mman.h>
#include <sys/resource.h>

static void			munmap_block(t_block *block)
{
	munmap(block, block->size + AL_BLOCK_SIZE);
}

static t_block		*search_block_in_heap(void *ptr, enum e_heap type)
{
	t_block *block;

	block = g_heap[type].used_blocks;
	while (block)
	{
		if ((char *)block + AL_BLOCK_SIZE == (char *)ptr)
			return (block);
		block = block->next;
	}
	return (NULL);
}

enum e_heap			find_block_by_ptr(void *ptr, t_block **block_ptr)
{
	if ((*block_ptr = search_block_in_heap(ptr, TINY)))
		return (TINY);
	if ((*block_ptr = search_block_in_heap(ptr, SMALL)))
		return (SMALL);
	if ((*block_ptr = search_block_in_heap(ptr, LARGE)))
		return (LARGE);
	return (INVALID);
}

void				free_block(enum e_heap type, t_block *block)
{
	static int i = 0;

	if (type != LARGE)
	{
		move_block_to_free(type, block);
		if (i == 5)
			defragment_heap(type);
		else
			++i;
	}
	else
	{
		remove_block(&g_heap[type].used_blocks, block);
		munmap_block(block);
	}
	check_heap();
}

__EXPOSE_VOID		free(void *ptr)
{
	t_block		*block;
	enum e_heap	type;

	if (ptr)
	{
		pthread_mutex_lock(&g_mutex);
		block = NULL;
		type = find_block_by_ptr(ptr, &block);
		if (type != INVALID)
			free_block(type, block);
		pthread_mutex_unlock(&g_mutex);
	}
}
