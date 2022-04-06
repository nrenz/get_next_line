/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:42:57 by nrenz             #+#    #+#             */
/*   Updated: 2022/04/06 17:56:07 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> // rm
# include <stdio.h> // rm

char	*get_next_line(int fd);
char	*ft_gnl_check(char *buffer, char *output, int fd);
char	*ft_found_textline(char *buffer, char *output);
char	*ft_realloc(char *s1, char *s2, int free_s1, int free_s2);
int		ft_strchr(char *buffer, char c);
int		ft_copy(char *dest, char *src, int len);
int		ft_strlen(char *str);

#endif