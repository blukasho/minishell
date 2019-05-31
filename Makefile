#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/05/28 17:41:01 by blukasho          #+#    #+#             *#
#*   Updated: 2019/05/31 15:17:07 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = minishell.c print_start_msg.c get_argv.c read_line.c

SRCS_DIR = srcs/

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJ_DIR = obj/

LIBFT_PATH = libft/

LIB_NAME = libft.a

NAME = minishell

CURR_PATH = .

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror -I includes

DEBUG_FLAGS = -g3 -fsanitize=address

MINISHELL_MAIN = srcs/main.c

all: make_lib make_objs_dir $(LIB_NAME) $(NAME)

set_debug_flags:
	@$(eval FLAGS=$(FLAGS) $(DEBUG_FLAGS))

debug: fclean make_debug_lib set_debug_flags all

make_debug_lib:
	make debug -C $(LIBFT_PATH)

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
