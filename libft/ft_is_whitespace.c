/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:54:06 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/19 10:56:46 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

bool	ft_is_whitespace(const char c)
{
	return (ft_strchr(" \n\t\r\a", c) != NULL);
}
