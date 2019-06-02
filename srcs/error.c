/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:51:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/02 15:43:24 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		error_command_not_found(t_minishell *s)
{
	if (s->argv && *(s->argv))
		ft_printf("%s: command not found\n", *(s->argv));
	return (0);
}
