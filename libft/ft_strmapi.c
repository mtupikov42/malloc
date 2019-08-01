/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:15:17 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:28:34 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	if (s)
	{
		i = 0;
		if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			if (!(ret[i] = f(i, s[i])))
				return (NULL);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
