# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 10:14:24 by nrenz             #+#    #+#              #
#    Updated: 2022/04/06 12:05:02 by nrenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = get_next_line.c \
		get_next_line_utils.c \

BONUS = get_next_line_bonus.c \
		get_next_line_utils_bonus.c \

HEADER = get_next_line.h

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY:	all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean:	clean
	rm -f $(OBJS)

re:	fclean $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)