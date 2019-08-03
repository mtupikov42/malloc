/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:41:08 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/03 17:39:10 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "t_block.h"

# define ALIGN(x, y)	(((x - 1) / y * y) + y)
# define ALIGN4(x)		ALIGN(x, 4)
# define BLOCK_SIZE		sizeof(struct s_block)
# define AL_BLOCK_SIZE	ALIGN4(BLOCK_SIZE)

#endif