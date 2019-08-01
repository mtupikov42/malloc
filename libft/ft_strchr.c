/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:33:09 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:26:33 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *str, const int symbol)
{
	while (*str)
	{
		if (*str == symbol)
			return ((char *)&*str);
		str++;
	}
	if (*str == symbol)
		return ((char *)&*str);
	return (NULL);
}
