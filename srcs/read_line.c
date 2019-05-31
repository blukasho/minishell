/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:15:06 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/31 15:29:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*read_line(void)
{
	char	*line;
	char	buf;
	int		ret;

	line = ft_strnew(2);
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{}
	return (line);
}
