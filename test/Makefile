#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/05/25 16:29:57 by blukasho          #+#    #+#             *#
#*   Updated: 2019/05/29 09:53:57 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = test_1.c test_2.c

OBJ_PATH = objs/

SRCS_PATH = srcs/

OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

FLAGS = -Wall -Wextra -Werror -I includes

LIBFT = libft.a

all: make_obj_path $(LIBFT)

make_obj_path:
	@mkdir -p $(OBJ_PATH)

$(LIBFT): $(OBJ)
	ar -rv $(LIBFT) $^
	ranlib $(LIBFT)

$(OBJ_PATH)%.o:$(SRCS_PATH)%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	rm -rf a.out
	rm -rf objs
	rm -rf a.out.dSYM

fclean: clean
	rm -rf $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
