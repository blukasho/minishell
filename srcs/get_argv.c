/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:07:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/31 15:17:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_argv(void)
{
	char	*input;
	char	**argv;

	argv = NULL;
	input = read_line();
	if (input && argv)
	{}
	return (argv);
}
