/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:55:52 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/02 13:56:29 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				clear_t_minishell(t_minishell *s)
{
	if (s && s->argv)
		clear_argv(s->argv);
	if (s && s->env)
		clear_argv(s->env);
	if (s && s->bin_paths)
		clear_argv(s->bin_paths);
	if (s)
		ft_memdel((void **)&s);
	return (0);
}
