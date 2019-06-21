/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:55:52 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/21 08:57:06 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				clear_t_minishell(t_minishell *s)
{
	if (s && s->argv)
		clear_argv(&(s->argv));
	if (s && s->env)
		clear_argv(&(s->env));
	if (s && s->env_paths)
		clear_argv(&(s->env_paths));
	if (s && s->bin_paths)
		clear_argv(&(s->bin_paths));
	if (s)
		ft_memdel((void **)&s);
	return (0);
}

int				clear_argv(char ***argv)
{
	char		**tmp;

	tmp = *argv;
	while (tmp && *tmp)
		ft_memdel((void **)&(*(tmp++)));
	if (*argv)
		free(*argv);
	*argv = NULL;
	return (0);
}
