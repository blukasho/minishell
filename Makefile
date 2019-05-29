#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/05/28 17:41:01 by blukasho          #+#    #+#             *#
#*   Updated: 2019/05/29 11:39:09 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = test.c

SRCS_DIR = srcs/

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJ_DIR = obj/

LIBFT_PATH = libft/

LIB_NAME = libft.a

NAME = minishell

CURR_PATH = .

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror -I includes

MINISHELL_MAIN = srcs/main.c

all: make_lib make_objs_dir $(LIB_NAME) $(NAME)

make_objs_dir:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(MINISHELL_MAIN)
	gcc $(FLAGS) $(MINISHELL_MAIN) $(LIB_NAME) -o $(NAME)

$(LIB_NAME): $(OBJ)
	ar -rv $(LIB_NAME) $^
	ranlib $(LIB_NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	gcc $(FLAGS) -c $< -o $@


make_lib:
	@make -C $(LIBFT_PATH)
	@cp -rf $(LIBFT_PATH)$(LIB_NAME) $(CURR_PATH)

make_re_lib:
	@make re -C $(LIBFT_PATH)

make_clean_lib:
	@make clean -C $(LIBFT_PATH)

make_fclean_lib:
	@make fclean -C $(LIBFT_PATH)

clean: make_clean_lib
	rm -rf $(OBJ_DIR)

fclean: make_fclean_lib clean
	rm -rvf $(LIB_NAME)
	rm -rvf $(NAME)

re: fclean all

.PHONY: all clean fclean re
