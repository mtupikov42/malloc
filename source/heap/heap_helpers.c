/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:06:46 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/03 17:23:55 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heap.h"
#include "t_block.h"

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
