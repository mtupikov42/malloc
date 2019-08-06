/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:41:51 by anonymous         #+#    #+#             */
/*   Updated: 2019/08/06 21:17:17 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "t_block.h"
#include "t_heap.h"
#include "free_impl.h"
#include "helpers.h"
#include "libft.h"
#include "globals.h"
#include "blocks.h"

static void		*realloc_impl(enum e_heap type, t_block *block, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	ft_memmove(new_ptr, (char *)block + AL_BLOCK_SIZE, block->size);
	pthread_mutex_lock(&g_mutex);
	free_block(type, block);
	pthread_mutex_unlock(&g_mutex);
	return (new_ptr);
}

__EXPOSE_VOID	*realloc(void *ptr, size_t size)
{
	t_block		*block;
	enum e_heap	type;

	if (!ptr)
		return (malloc(size));
	pthread_mutex_lock(&g_mutex);
	block = NULL;
	type = find_block_by_ptr(ptr, &block);
	pthread_mutex_unlock(&g_mutex);
	if (type != INVALID)
	{
		if (size <= block->size)
			return (ptr);
		else
			return (realloc_impl(type, block, size));
	}
	return (NULL);
}
