/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:07:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/24 18:42:15 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replace_not_print_symbols(char *str)
{
	while (str && *str)
	{
		if (!ft_isprint(*str))
			*str = ' ';
		++str;
	}
}

static void	skip_quotes(char *str)
{
	char	*tmp;

	while ((tmp = ft_strchr(str, '\'')))
		ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
	while ((tmp = ft_strchr(str, '\"')))
		ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
}

static char	***manage_semi_colon(char *str)
{
	char	***argvs;
	char	**sem_col;
	int		len;

	len = 0;
	sem_col = ft_strsplit(str, ';');
	argvs = (char ***)malloc((ft_strlenarr(sem_col) + 1) * sizeof(char **));
	while (sem_col[len])
	{
		argvs[len] = ft_strsplit(sem_col[len], ' ');
		++len;
	}
	argvs[len] = NULL;
	ft_str_del_arr(sem_col);
	return (argvs);
}

char		***get_argv(char **env)
{
	char	*tmp;
	char	*input;
	char	***argvs;

	tmp = read_line();
	replace_not_print_symbols(tmp);
	skip_quotes(tmp);
	input = manage_expansions(tmp, env);
	argvs = manage_semi_colon(input);
	if (tmp)
		ft_memdel((void **)&tmp);
	if (input)
		ft_memdel((void **)&input);
	return (argvs);
}
