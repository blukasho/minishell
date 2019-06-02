/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:50:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/02 15:39:44 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		start_minishell(t_minishell *s)
{
	if (!((s->bin_path) = get_bin_path(s)) && !error_command_not_found(s))
		return (1);
	return (0);
}

int				minishell(char **env)
{
	t_minishell	*s;

	s = get_t_minishell(env);
	while (1)
	{
		print_start_msg();
		s->argv = get_argv();
		if ((check_exit(s) && !clear_t_minishell(s)) || !start_minishell(s))
			return (0);
		clear_argv(s->argv);
	}
	return (0);
} 
