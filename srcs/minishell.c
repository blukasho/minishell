/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:50:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/01 14:53:21 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				minishell(char **env)
{
	t_minishell	*s;

	s = get_t_minishell(env);
	while (1)
	{
		print_start_msg();
		s->argv = get_argv();
		if (check_builtins(s))
			return (0);
		clear_argv(s->argv);
	}
	return (0);
} 
