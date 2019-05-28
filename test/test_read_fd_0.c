/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read_fd_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:36:39 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/28 18:14:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/test.h"

char		*realloc_str(char *s1, char c, int len)
{
	char	*res;

	res = ft_strnew(len + 1);
	ft_strncpy(res, s1, len);
	res[len - 1] = c;
	ft_memdel((void **)&s1);
	return (res);
}

int			main(void)
{
	char	*input;
	char	*tmp;
	char	buf;
	int		count;

	count = 0;
	input = ft_strnew(1);
	while (read(0, &buf, 1) != -1 && buf != '\n' && ++count)
		input = realloc_str(input, buf, count);
	ft_printf("read string |%s|\n", input);
	ft_memdel((void **)&input);
	return (0);
}
