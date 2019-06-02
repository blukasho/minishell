/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:02:30 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/02 14:04:38 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_exit(t_minishell *s)
{
	if (s && s->argv && s->argv[0] && !ft_strcmp(s->argv[0], "exit"))
		return (1);
	return (0);
}
