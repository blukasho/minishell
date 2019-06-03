/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:07:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/01 12:51:27 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_argv(void)
{
	char	*input;
	char	**argv;

	input = read_line();
	argv = ft_strsplit(input, ' ');
	if (input)
		ft_memdel((void **)&input);
	return (argv);
}