/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:12:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/01 14:43:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**get_dup_string_arr(char **arr)
{
	char		**res;
	int			len;

	len = 0;
	res = arr;
	while (res && *res && ++len)
		++res;
	res = (char **)malloc(++len * sizeof(char *));
	len = 0;
	if (res)
		while (arr[len])
		{
			res[len] = ft_strdup(arr[len]);
			++len;
		}
	res[len] = NULL;
	return (res);
}

int				clear_t_minishell(t_minishell *s)
{
	if (s && s->argv)
		clear_argv(s->argv);
	if (s && s->env)
		clear_argv(s->env);
	if (s)
		ft_memdel((void **)&s);
	return (0);
}

t_minishell		*get_t_minishell(char **env)
{
	t_minishell	*s;

	if (env)
	{}
	s = (t_minishell *)malloc(sizeof(t_minishell));
	if (s)
	{
		ft_bzero(s, sizeof(t_minishell));
		s->env = get_dup_string_arr(env);
	}
	return (s);
}
