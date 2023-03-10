# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 15:27:21 by mimatsub          #+#    #+#              #
#    Updated: 2023/02/20 14:04:17 by mimatsub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = push_swap.c error_ps.c make_list_ps.c make_list_ps_utils.c less_than_six_ps.c more_than_seven_ps.c push.c swap.c rotate.c r_rotate.c \
		libft/ft_strlen.c libft/ft_atoi.c libft/ft_atol.c libft/ft_isdigit.c libft/ft_strncmp.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c
OBJS = $(SRCS:.c=.o)

all:	$(NAME)


$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)



clean:	
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re