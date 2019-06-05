/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:50:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/05 14:55:37 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		start_minishell(t_minishell *s)
{
	if (check_exit(s))
		return (clear_t_minishell(s));
	if (!((s->bin_paths) = get_bin_paths(s)) && !error_command_not_found(*(s->argv)))
		return (1);
	if (is_dir(*(s->argv)) && !error_is_dir(*(s->argv)))
		return (1);
	if (!is_file(*(s->argv)) && !error_no_such_file_or_directory(*(s->argv)))
		return (1);
	return (0);
}

int				minishell(char **env)
{
	t_minishell	*s;

	s = get_t_minishell(env);
	while (!0)
	{
		print_start_msg();
		s->argv = get_argv();
		if (*(s->argv) && !start_minishell(s) && !clear_t_minishell(s))
			return (0);
		clear_argv(s->argv);
		s->argv = NULL;
		clear_argv(s->bin_paths);
		s->bin_paths = NULL;
	}
	return (0);
} 
