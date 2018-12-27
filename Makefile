# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbartol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 12:56:28 by flbartol          #+#    #+#              #
#    Updated: 2018/12/27 16:28:26 by flbartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit
FLAGS= -Wall -Wextra -Werror 
SRC= check_tab.c display.c input.c aux.c main.c map.c

OBJ := $(SRC:.c=.o)
SRC := $(SRC)
HEADER = fillit.h 
LIBFT = libft/

all: $(NAME)

$(NAME) : $(SRC) $(OBJ) $(LIBFT)
	@make -C $(LIBFT)
	@gcc $(FLAGS) -o $@ -c $< -I $(HEADER)
	@gcc $(OBJ) -L $(LIBFT) -lft -o $(NAME) 

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: clean fclean re all