/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_block.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:35:12 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/03 17:18:21 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BLOCK_H
# define T_BLOCK_H

# include <pthread.h>

# define MIN_BLOCKS_ALLOC	100
# define TINY_BLOCK			256
# define SMALL_BLOCK		4096

typedef struct			s_block
{
	size_t				size;
	struct s_block		*next;
	struct s_block		*prev;
}						t_block;

#endif