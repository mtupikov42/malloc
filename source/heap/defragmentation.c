/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defragmentation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:08:05 by anonymous         #+#    #+#             */
/*   Updated: 2019/08/04 11:15:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heap.h"
#include "globals.h"
#include "helpers.h"

static void	pair_blocks(t_block *lhs, t_block *rhs)
{
	lhs->size += rhs->size + AL_BLOCK_SIZE;
	lhs->next = rhs->next;
	if (rhs->next)
		rhs->next->prev = lhs;
}

void		defragment_heap(enum e_heap type)
{
	t_block		*block;

	if (type != INVALID)
	{
		block = g_heap[type].free_blocks;
		while (block)
			if (block->next && (char *)block->next ==
				(char *)block + AL_BLOCK_SIZE + block->size)

			else
				block = block->next;	
	}
}