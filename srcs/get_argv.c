/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:07:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/31 16:25:48 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_argv(void)
{
	char	*input;
	char	**argv;

	argv = NULL;
	input = read_line();
	ft_printf("input |%s|\n", input);
	argv = ft_strsplit(input, ' ');
	while (*argv)
		ft_printf("|%s|\n", argv++);
	if (input && argv)
	{}
	return (argv);
}
