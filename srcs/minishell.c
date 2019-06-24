/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:50:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/24 19:38:40 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		construction_minishell(t_minishell *s)
{
	if (check_exit(s))
		return (0);
	if (check_builtins(s))
		return (1);
	if (!((s->bin_paths) = get_bin_paths(s)) && !is_way(*(s->argv)) &&
		!put_error(*(s->argv), "command not found"))
		return (1);
	if (check_errors_minishell(s))
		return (1);
	return (run_minishell(s));
}

static int		clear_argvs(char ***argvs)
{
	free(argvs);
	return (0);
}

static int		local_clear(t_minishell *s)
{
	clear_argv(&(s->bin_paths));
	if (!clear_argv(&(s->argv)) && s->env_paths)
		clear_argv(&(s->env_paths));
	return (0);
}

int				minishell(char **env)
{
	t_minishell	*s;
	char		***argvs;
	char		***tmp;

	if (!(s = NULL) && !print_welcome())
		s = get_t_minishell(env);
	signal(SIGINT, setsignalhandler);
	while (!0 && !(tmp = NULL) && !print_start_msg())
	{
		argvs = get_argv(s->env);
		tmp = argvs;
		while (*argvs)
		{
			s->argv = *(argvs++);
			if (*(s->argv) && !construction_minishell(s) &&
				!clear_t_minishell(s))
				return (clear_argvs(tmp));
			local_clear(s);
			s->env_paths = get_env_paths(s->env);
		}
		clear_argvs(tmp);
	}
	return (0);
}
