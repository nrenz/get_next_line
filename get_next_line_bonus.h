/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:57:12 by nrenz             #+#    #+#             */
/*   Updated: 2022/04/19 17:04:01 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_gnl_check(char *buffer, char *output, int fd);
char	*ft_found_new_line(char *buffer, char *output);
char	*ft_realloc(char *s1, char *s2, int free_s1, int free_s2);
char	*ft_strchr(char *buffer, char c);
int		ft_copy(char *dest, char *src, int len);
int		ft_strlen(char *str);

#endif