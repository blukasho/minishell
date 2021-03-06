/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:40:18 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/21 10:11:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**realloc_env(char **env, char *name_env)
{
	char	**tmp_env;
	char	**res;
	int		len;

	len = 0;
	tmp_env = env;
	while (*tmp_env && ++len)
		++tmp_env;
	tmp_env = (char **)malloc(++len * sizeof(char *));
	res = tmp_env;
	*res = NULL;
	if (!ft_strcmp(name_env, "--all=") && !ft_str_del_arr(env))
		return (tmp_env);
	len = 0;
	while (env[len])
		if (ft_strncmp(name_env, env[len], ft_strlen(name_env)))
		{
			*tmp_env = ft_strdup(env[len++]);
			++tmp_env;
		}
		else
			++len;
	*tmp_env = NULL;
	ft_str_del_arr(env);
	return (res);
}

int			minishell_unsetenv(t_minishell *s)
{
	char	**argv;
	char	**env;
	char	*var_name;

	env = s->env;
	argv = s->argv;
	if (!*(++argv))
		return (put_error("ERROR unsetenv,", "need env variable name"));
	var_name = ft_strjoin(*argv, "=");
	if (var_name)
	{
		s->env = realloc_env(env, var_name);
		ft_memdel((void **)&var_name);
	}
	return (0);
}
