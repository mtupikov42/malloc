/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:35:38 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:23:57 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *restrict memptr, const int val, const size_t num)
{
	char	*mem;
	size_t	i;

	mem = (char *)memptr;
	i = 0;
	while (i < num)
	{
		mem[i] = val;
		i++;
	}
	return (memptr);
}
