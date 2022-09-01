# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 18:10:19 by lwilliam          #+#    #+#              #
#    Updated: 2022/08/23 10:36:32 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

C_SRC = client.c

S_SRC = server.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	make libft
	$(CC) $(CFLAGS) $(C_SRC) $(NAME) -o client
	$(CC) $(CFLAGS) $(S_SRC) $(NAME) -o server

libft:
	make -C libft_printf
	cp libft_printf/libft.a .
	mv libft.a $(NAME)

clean :
	rm -f *.o
	make clean -C libft_printf

fclean : clean
	rm -f minitalk.a client server
	make fclean -C libft_printf


re : fclean all
	make re -C libft_printf