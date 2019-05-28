#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/05/28 17:41:01 by blukasho          #+#    #+#             *#
#*   Updated: 2019/05/28 19:33:32 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

vpath %.c srcs

SRCS = main.c

OBJ = $(SRCS:.c=.o)

LIBFT_PATH = libft/

LIB_NAME = libft.a

NAME = minishell

CURR_PATH = .

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror -I includes

all: make_lib $(NAME)

$(OBJ): %.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rv $(LIBFT) $^
	ranlib $(LIBFT)

make_lib:
	make -C $(LIBFT_PATH)
	cp -rvf $(LIBFT_PATH)$(LIB_NAME) $(CURR_PATH)

make_re_lib:
	make re -C $(LIBFT_PATH)

make_clean_lib:
	make clean -C $(LIBFT_PATH)

make_fclean_lib:
	make fclean -C $(LIBFT_PATH)

clean: make_clean_lib

fclean: make_fclean_lib
	rm -rvf $(LIB_NAME)
	rm -rvf $(NAME)
