/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:56:14 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/03 17:23:34 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blocks.h"
#include "globals.h"
#include "helpers.h"
#include <sys/mman.h>
#include <sys/resource.h>
#include <unistd.h>

t_block			*allocate_memory(void *ptr, size_t size)
{
	t_block *block;

	block = mmap(ptr, size, PROT_READ | PROT_WRITE | PROT_EXEC,
				MAP_ANON | MAP_PRIVATE, -1, 0);
	if (block == MAP_FAILED)
		return (NULL);
	return (block);
}

static t_block	*extend_free_zone(t_block *last, enum e_heap type, size_t size)
{
	t_block	*block;
	size_t	pages;

	if (type == TINY)
		pages = ALIGN(TINY_BLOCK + AL_BLOCK_SIZE * MIN_BLOCKS_ALLOC,
			getpagesize());
	else if (type == SMALL)
		pages = ALIGN(SMALL_BLOCK + AL_BLOCK_SIZE * MIN_BLOCKS_ALLOC,
			getpagesize());
	else
		pages = ALIGN(size + AL_BLOCK_SIZE * MIN_BLOCKS_ALLOC, getpagesize());
	block = allocate_memory(last + AL_BLOCK_SIZE, pages);
	if (block)
	{
		block->size = pages - AL_BLOCK_SIZE;
		block->prev = last;
		block->next = NULL;
	}
	return (block);
}

static t_block	*add_free_block(t_block *last, enum e_heap type, size_t size)
{
	if (last)
	{
		last->next = extend_free_zone(last, type, size);
		return (last->next);
	}
	g_heap[type].free_blocks = extend_free_zone(last, type, size);
	return (g_heap[type].free_blocks);
}

t_block			*find_free_block(enum e_heap type, size_t size)
{
	t_block *block;
	t_block	*last;

	block = g_heap[type].free_blocks;
	last = NULL;
	while (block)
	{
		last = block;
		if (block->size >= size)
			return (block);
		block = block->next;
	}
	return (add_free_block(last, type, size));
}
