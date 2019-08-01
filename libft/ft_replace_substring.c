/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_substring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:28:49 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:13:16 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	*get_occurance(const char *str, const char *word)
{
	int		*arr;
	int		len;

	if (!(arr = (int *)ft_memalloc(sizeof(int) * 2)))
	{
		return (NULL);
	}
	len = ft_strlen(word);
	while (str[arr[0]])
	{
		if (ft_strstr(&str[arr[0]], word) == &str[arr[0]])
		{
			arr[1]++;
			arr[0] += len - 1;
		}
		++arr[0];
	}
	return (arr);
}

char		*ft_replace_substring(const char *str,
			const char *old, const char *new)
{
	char	*result;
	int		i;
	int		*helper;
	int		new_len;
	int		old_len;

	new_len = ft_strlen(new);
	old_len = ft_strlen(old);
	if (!(helper = get_occurance(str, old)))
		return (NULL);
	result = ft_memalloc(helper[0] + helper[1] * (new_len - old_len) + 1);
	i = 0;
	while (*str)
		if (ft_strstr(str, old) == str)
		{
			ft_strcpy(&result[i], new);
			i += new_len;
			str += old_len;
		}
		else
			result[i++] = *str++;
	result[i] = '\0';
	free(helper);
	return (result);
}
