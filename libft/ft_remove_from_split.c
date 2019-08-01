/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_from_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:01:20 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 18:45:51 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_remove_from_split_c(char **split, char *var, char c)
{
	int		len;
	int		i;
	int		j;
	char	**new_split;

	i = 0;
	j = 0;
	len = ft_strsplit_count((const char **)split);
	new_split = (char **)ft_memalloc(sizeof(char *) * len);
	while (split[i])
	{
		if (ABS(ft_strcmp(split[i], var)) != c)
		{
			new_split[j] = split[i];
			++j;
		}
		else
		{
			free(split[i]);
		}
		++i;
	}
	return (new_split);
}

char	**ft_remove_from_split(char **split, char *var)
{
	return (ft_remove_from_split_c(split, var, 0));
}
