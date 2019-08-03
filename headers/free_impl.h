/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_impl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:28:15 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/03 19:29:15 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_IMPL_H
# define FREE_IMPL_H

# include "t_heap.h"
# include "t_block.h"

void	free_block(enum e_heap type, t_block *block);

#endif