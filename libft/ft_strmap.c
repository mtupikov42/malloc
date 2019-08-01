/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:08:53 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:28:29 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	if (s)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			if (!(ret[i] = f(s[i])))
				return (NULL);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
