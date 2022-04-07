/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:06:38 by nrenz             #+#    #+#             */
/*   Updated: 2022/04/07 17:35:44 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	output = (char *)malloc(BUFFER_SIZE + 1);
	if (!output)
		return (NULL);
	output[0] = '\0';
	return (ft_gnl_check(buffer, output, fd));
}

char	*ft_gnl_check(char *buffer, char *output, int fd)
{
	ssize_t	read_done;

	while (1)
	{
		if (buffer[0])
		{
			if (ft_strchr(buffer, '\n'))
			{
				return (ft_found_textline(buffer, output));
			}
			output = ft_realloc(output, buffer, 1, 0);
		}
		read_done = read(fd, buffer, BUFFER_SIZE);
		if (read_done == -1 || (read_done == 0 && output[0] == '\0'))
		{
			free(output);
			return (NULL);
		}
		buffer[read_done] = '\0';
		if (read_done == 0)
		{
			return (output);
		}
	}
}

char	*ft_found_textline(char *buffer, char *output)
{
	int		cut_size;
	char	*tmp;

	tmp = (char *)malloc(BUFFER_SIZE);
	cut_size = (ft_strchr(buffer, '\n') - buffer) + 1;
	if (!tmp)
		return (NULL);
	ft_copy(tmp, buffer, cut_size + 1);
	output = ft_realloc(output, tmp, 1, 1);
	ft_copy(buffer, &buffer[cut_size], 0);
	return (output);
}

char	*ft_realloc(char *s1, char *s2, int free_s1, int free_s2)
{
	int		strlen_s1;
	int		strlen_s2;
	char	*new_output;
	int		count;

	strlen_s1 = ft_strlen(s1);
	strlen_s2 = ft_strlen(s2);
	new_output = (char *)malloc(strlen_s1 + strlen_s2 + 1);
	if (!new_output)
		return (NULL);
	count = ft_copy(new_output, s1, 0);
	ft_copy(&new_output[count], s2, 0);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (new_output);
}

// int	main(void)
// {
// 	int				fd;
// 	char			*str;
// 	int i = 0;

// 	fd = open("textfile.txt", O_RDWR);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 			break ;
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	return (0);
// }
