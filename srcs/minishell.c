/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:50:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/10 17:26:10 by blukasho         ###   ########.fr       */
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

int				minishell(char **env)
{
	t_minishell	*s;

	s = get_t_minishell(env);
	while (!0)
	{
		print_start_msg();
		s->argv = get_argv();
		if (*(s->argv) && !construction_minishell(s) && !clear_t_minishell(s))
			return (0);
		clear_argv(&(s->argv));
		clear_argv(&(s->bin_paths));
	}
	return (0);
}
