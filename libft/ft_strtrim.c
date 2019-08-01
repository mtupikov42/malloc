/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:01:57 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 14:17:58 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(const char *s)
{
	char	*ret;
	int		j;
	int		i;
	int		k;

	if (s)
	{
		i = 0;
		while (s[i] && ft_is_whitespace(s[i]))
			i++;
		j = ft_strlen(s) - 1;
		if (!(ret = (char *)malloc(sizeof(char) * (j - i + 1))))
			return (NULL);
		while (j >= 0 && ft_is_whitespace(s[i]))
			j--;
		k = -1;
		while (i <= j)
		{
			ret[++k] = s[i];
			i++;
		}
		ret[++k] = '\0';
		return (ret);
	}
	return (NULL);
}
