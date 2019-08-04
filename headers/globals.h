/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 11:28:23 by mtupikov          #+#    #+#             */
/*   Updated: 2019/08/04 16:41:56 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

# include <pthread.h>
# include "t_heap.h"

extern pthread_mutex_t	g_mutex;
t_heap					g_heap[3];

#endif
