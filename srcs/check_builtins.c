/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:40:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/01 15:06:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_builtins(t_minishell *s)
{
	if (s && s->argv && s->argv[0] && !ft_strcmp(s->argv[0], "exit")
		&& !clear_t_minishell(s))
		return (1);
	return (0);
}
