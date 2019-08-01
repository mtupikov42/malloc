/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:23:40 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:29:28 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(const char *s1, const char *s2, const size_t n)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return (0);
		s1++;
		s2++;
		i++;
	}
	return (1);
}
