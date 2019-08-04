/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:06:46 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/04 17:52:57 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heap.h"
#include "t_block.h"
#include "globals.h"
#include "helpers.h"
#include "blocks.h"
#include <sys/mman.h>
#include <sys/resource.h>
#include <unistd.h>

enum e_heap		get_zone_type_from_block_size(size_t size)
{
	if (size <= TINY_BLOCK)
		return (TINY);
	else if (size <= SMALL_BLOCK)
		return (SMALL);
	return (LARGE);
}

int				get_block_size_from_zone_type(enum e_heap type)
{
	if (type == TINY)
		return (TINY_BLOCK);
	return (SMALL_BLOCK);
}

static void		check_heap_impl(enum e_heap type, size_t heap_max_size)
{
	t_block *block;

	if (g_heap[type].free_blocks)
	{
		block = g_heap[type].free_blocks;
		while (block)
		{
			if (block->size == heap_max_size)
			{
				munmap(block, heap_max_size);
				remove_block(&g_heap[type].free_blocks, block);
			}
			block = block->next;
		}
	}
}

void			check_heap(void)
{
	static int counter = 0;

	if (counter == 5)
	{
		check_heap_impl(TINY, ALIGN(TINY_BLOCK + AL_BLOCK_SIZE *
			MIN_BLOCKS_ALLOC, getpagesize()));
		check_heap_impl(SMALL, ALIGN(SMALL_BLOCK + AL_BLOCK_SIZE *
			MIN_BLOCKS_ALLOC, getpagesize()));
		counter = 0;
	}
	else
		counter++;
}
