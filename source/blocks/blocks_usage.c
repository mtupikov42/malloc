/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:05:08 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/03 14:22:20 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blocks.h"
#include "globals.h"

void	remove_block(t_block **start, t_block *block)
{
	if (block->next)
		block->next->prev = block->prev;
	if (block->prev)
		block->prev->next = block->next;
	if (*start == block)
		*start = block->next;
}

void	push_block_on_top(t_block **start, t_block *block)
{
	if (!*start)
	{
		*start = block;
		block->next = NULL;
		block->prev = NULL;
	}
	else
	{
		block->next = *start;
		block->prev = NULL;
		(*start)->prev = block;
		*start = block;
	}
}

void	move_block_to_used(enum e_heap type, t_block *block)
{
	remove_block(&g_heap[type].free_blocks, block);
	push_block_on_top(&g_heap[type].used_blocks, block);
}