/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:15:49 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/04 16:28:22 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "globals.h"
#include "t_heap.h"
#include "libft.h"
#include "helpers.h"

static void	print_block(t_block	*block)
{
	ft_printf("%#x - %#x : %d bytes\n",
			(char *)block,
			(char *)block + block->size + AL_BLOCK_SIZE,
			block->size);
}

static void print_heap(t_block *block)
{
	while (block)
	{
		print_block(block);
		block = block->next;
	}
}

static void	show_zone(enum e_heap type, const char *zone_name)
{
	ft_printf("Free %s zone:\n", zone_name);
	print_heap(g_heap[type].free_blocks);
	ft_printf("Used %s zone:\n", zone_name);
	print_heap(g_heap[type].used_blocks);
}

void		show_alloc_mem()
{
	pthread_mutex_lock(&g_mutex);
	show_zone(TINY, "TINY");
	show_zone(SMALL, "SMALL");
	show_zone(LARGE, "LARGE");
	pthread_mutex_unlock(&g_mutex);
}