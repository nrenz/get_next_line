/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:14:54 by nrenz             #+#    #+#             */
/*   Updated: 2022/04/07 17:37:31 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *buffer, char c)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (&buffer[i]);
		i++;
	}
	return (NULL);
}

int	ft_copy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	if (len == 0)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		len--;
		while (i < len && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
