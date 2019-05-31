/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:15:06 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/31 16:16:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*str_realloc(char *str, char c, int	len)
{
	char	*buf;

	buf = ft_strnew(len + 2);
	ft_strcpy(buf, str);
	buf[len] = c;
	ft_memdel((void **)&str);
	return (buf);
}

char		*read_line(void)
{
	char	*line;
	char	buf;
	int		ret;
	int		len;

	line = ft_strnew(1);
	len = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
		line = str_realloc(line, buf, len++);
	return (line);
}
