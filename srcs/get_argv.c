/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:07:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/23 12:47:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replace_tabs(char *str)
{
	while (str && *str)
	{
		if (!ft_isprint(*str))
			*str = ' ';
		++str;
	}
}

static void skip_quotes(char *str)
{
	char	*tmp;

	while ((tmp = ft_strchr(str, '\'')))
		ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
	while ((tmp = ft_strchr(str, '\"')))
		ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
}

char		**get_argv(char **env)
{
	char	*tmp;
	char	*input;
	char	**argv;

	tmp = read_line();
	replace_tabs(tmp);
	skip_quotes(tmp);
	input = manage_expansions(tmp, env);
	argv = ft_strsplit(input, ' ');
	if (tmp)
		ft_memdel((void **)&tmp);
	if (input)
		ft_memdel((void **)&input);
	return (argv);
}
