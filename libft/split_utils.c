/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:54:13 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:46:57 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"

int		ft_strsplit_count(const char **split)
{
	int len;
	int i;

	if (!split)
		return (0);
	len = 0;
	i = -1;
	while (split[++i])
		len++;
	return (len);
}

char	**ft_append_to_split(char **split, char *str)
{
	char	**res;
	int		old_len;

	old_len = ft_strsplit_count((const char **)split);
	res = (char **)ft_memalloc(sizeof(char *) * (old_len + 2));
	ft_memcpy(res, split, sizeof(char *) * old_len);
	res[old_len] = str;
	free(split);
	return (res);
}

int		ft_split_has_dupl(const char **split)
{
	int i;
	int j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[++j])
			if (i != j)
			{
				if (!ft_strcmp(split[i], split[j]))
					return (1);
			}
	}
	return (0);
}

char	**ft_splitrealloc(char **old, int size)
{
	char	**new;
	int		i;

	new = ft_memalloc(sizeof(char *) * size);
	if (!old)
	{
		new[size] = NULL;
		return (new);
	}
	i = -1;
	while (++i < size - 1)
	{
		new[i] = ft_strrealloc(new[i], ft_strlen(old[i]));
		ft_strcpy(new[i], old[i]);
	}
	new[size - 1] = NULL;
	new[size] = NULL;
	ft_splitdel(&old);
	return (new);
}

void	print_split(const char **split)
{
	int i;

	i = -1;
	while (split[++i])
		ft_printf("%s\n", split[i]);
}
