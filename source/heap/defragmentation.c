/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defragmentation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:08:05 by anonymous         #+#    #+#             */
/*   Updated: 2019/08/04 16:24:45 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heap.h"
#include "globals.h"
#include "helpers.h"
#include "blocks.h"

static int	are_near(t_block *lhs, t_block *rhs)
{
	return (lhs && rhs &&
		(char *)rhs == (char *)lhs + AL_BLOCK_SIZE + lhs->size);
}

static void	pair_blocks(t_block *lhs, t_block *rhs)
{
	lhs->size += rhs->size + AL_BLOCK_SIZE;
}

void		defragment_heap(enum e_heap type)
{
	t_block		*block;
	t_block		*d_block;

	if (type != INVALID)
	{
		block = g_heap[type].free_blocks;
		while (block)
		{
			d_block = g_heap[type].free_blocks;
			while (d_block)
			{
				if (are_near(block, d_block))
				{
					pair_blocks(block, d_block);
					remove_block(&g_heap[type].free_blocks, d_block);
				}
				else
					d_block = d_block->next;
			}
			block = block->next;
		}
	}
}
