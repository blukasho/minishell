#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/05/25 16:29:57 by blukasho          #+#    #+#             *#
#*   Updated: 2019/05/28 18:18:59 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = test_read_fd_0.c

INCLUDES = ../includes

all: make_lib
	gcc -g3 $(SRCS) ../libft.a -I $(INCLUDES)

make_lib:
	make make_lib -C ../

clean:
	rm -rf a.out
	rm -rf a.out.dSYM

fclean: clean
