/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:21:12 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/04 17:51:21 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_impl.h"
#include "blocks.h"
#include "t_heap.h"
#include "helpers.h"
#include <unistd.h>
#include "globals.h"

static t_block	*split_block(t_block *block, enum e_heap type, size_t size)
{
	t_block *split_block;
	int		m_size;

	m_size = get_block_size_from_zone_type(type);
	if (((block->size - size) >= (m_size + AL_BLOCK_SIZE))
		|| ((int)block->size - m_size >= 0))
	{
		split_block = (t_block *)((char *)block + AL_BLOCK_SIZE + size);
		split_block->size = block->size - size - AL_BLOCK_SIZE;
		split_block->prev = block;
		split_block->next = block->next;
		block->size = size;
		if (block->next)
			block->next->prev = split_block;
		block->next = split_block;
		return (split_block);
	}
	return (block->next);
}

static t_block	*alloc_large_block(size_t size)
{
	t_block	*block;
	size_t	pages;

	pages = ALIGN(size + AL_BLOCK_SIZE, getpagesize());
	block = allocate_memory(NULL, pages);
	if (block)
	{
		block->size = pages - AL_BLOCK_SIZE;
		block->prev = NULL;
		block->next = NULL;
		push_block_on_top(&g_heap[LARGE].used_blocks, block);
	}
	return (block);
}

t_block			*allocate_block(enum e_heap type, size_t size)
{
	t_block	*block;

	if (type == TINY || type == SMALL)
	{
		block = find_free_block(type, size);
		if (block)
		{
			block->next = split_block(block, type, size);
			move_block_to_used(type, block);
		}
	}
	else
		block = alloc_large_block(size);
	check_heap();
	return (block);
}
