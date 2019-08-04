/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:41:51 by anonymous         #+#    #+#             */
/*   Updated: 2019/08/04 11:04:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "t_block.h"
#include "t_heap.h"
#include "free_impl.h"
#include "helpers.h"
#include "libft.h"

static void	*realloc_impl(enum e_heap type, t_block *block, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	ft_memmove(new_ptr, (char *)block + AL_BLOCK_SIZE, block->size);
	free_block(type, block);
	return (new_ptr);
}

void	*realloc(void *ptr, size_t size)
{
	t_block		*block;
	enum e_heap	type;

	if (!ptr)
		return (malloc(size));
	pthread_mutex_lock(&g_mutex);
	block = NULL;
	type = find_block_by_ptr(ptr, &block);
	if (type != INVALID)
	{
		if (size <= block->size)
			return (ptr);
		else
			return (realloc_impl(type, block, size));
	}
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}
