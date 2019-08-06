/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:41:08 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/06 21:23:09 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "t_block.h"

# define ALIGN(x, y)	(((x - 1) / y * y) + y)
# define ALIGN4(x)		ALIGN(x, 4)
# define BLOCK_SIZE		sizeof(struct s_block)
# define AL_BLOCK_SIZE	ALIGN4(BLOCK_SIZE)
# define __EXPOSE		__attribute__((visibility ("default")))
# define __EXPOSE_VOID	void __EXPOSE

#endif
