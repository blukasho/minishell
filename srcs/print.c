/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 09:52:23 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/13 09:54:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			print_start_msg(void)
{
	char	*path;

	if ((path = getcwd(NULL, 0)))
	{
		ft_printf("minishell %s:", path);
		ft_strdel(&path);
	}
	ft_printf("%s", MINISHELL_START_MSG);
	return (0);
}

int			print_welcome(void)
{
	return (0);
}
