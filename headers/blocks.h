/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:56:27 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/03 17:23:50 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCKS_H
# define BLOCKS_H

# include "t_block.h"
# include "t_heap.h"

t_block	*allocate_memory(void *ptr, size_t size);
t_block	*find_free_block(enum e_heap type, size_t size);
void	remove_block(t_block **start, t_block *block);
void	push_block_on_top(t_block **start, t_block *block);
void	move_block_to_used(enum e_heap type, t_block *block);

#endif