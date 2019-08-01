/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 03:47:07 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:17:57 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_count_words(const char *s, const char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			s++;
			if (*s == c || ft_strlen(s) == 0)
				count++;
		}
	}
	return (count);
}
