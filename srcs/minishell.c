/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:50:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/04 16:53:00 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		start_minishell(t_minishell *s)
{
	if (check_exit(s))
		return (clear_t_minishell(s));
	if (!((s->bin_path) = get_bin_path(s)) && !error_command_not_found(s))
		return (1);
	if (is_dir(s->bin_path) && !error_is_dir(s))
		return (1);
	if (!is_file(s->bin_path) && !error_no_such_file_or_directory(s))
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
		if (*(s->argv) && !start_minishell(s))
			return (0);
		clear_argv(s->argv);
		ft_memdel((void **)&(s->bin_path));
	}
	return (0);
} 
