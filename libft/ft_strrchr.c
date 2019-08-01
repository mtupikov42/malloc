/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:51:49 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:30:23 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, const int symbol)
{
	int i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == symbol)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == symbol)
		return ((char *)&str[i]);
	return (NULL);
}
