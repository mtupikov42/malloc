/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:11:52 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:30:52 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrealloc(char *old_buf, const size_t size)
{
	char *new_buf;

	if (!old_buf)
	{
		new_buf = ft_strnew(size);
		return (new_buf);
	}
	new_buf = ft_strnew(ft_strlen(old_buf) + size);
	ft_strcpy(new_buf, old_buf);
	ft_strdel(&old_buf);
	return (new_buf);
}
