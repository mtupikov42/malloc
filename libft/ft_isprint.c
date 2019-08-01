/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:23:45 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:18:45 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(const int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}