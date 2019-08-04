/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 11:21:34 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/04 11:10:26 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HEAP_H
# define T_HEAP_H

# include "t_block.h"

enum			e_heap
{
	TINY = 0,
	SMALL,
	LARGE,
	INVALID = -1
};

typedef struct	s_heap
{
	t_block		*free_blocks;
	t_block		*used_blocks;
}				t_heap;

enum e_heap		get_zone_type_from_block_size(size_t size);
int				get_block_size_from_zone_type(enum e_heap type);
void			defragment_heap(enum e_heap type);

#endif