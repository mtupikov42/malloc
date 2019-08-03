/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_impl.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:19:18 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/03 14:22:48 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_IMPL_H
# define MALLOC_IMPL_H

# include "t_block.h"
# include "t_heap.h"

t_block	*allocate_block(enum e_heap type, size_t size);

#endif