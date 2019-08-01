/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 12:38:56 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:29:36 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(const size_t size)
{
	char *ret;

	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
