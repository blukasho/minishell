/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:34:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/10 18:41:24 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			echo(t_minishell *s)
{
	char	**argv;
	int		nl;

	argv = s->argv;
	++argv;
	if (*argv)
	{
		nl = (!ft_strcmp(*argv, "-n") ? 0 : 1);
		if (!nl)
			++argv;
		while (*argv && ft_printf("%s", *(argv++)))
			if (*argv)
				ft_printf(" ");
		if (nl)
			ft_printf("\n");
		return (0);
	}
	ft_printf("\n");
	return (0);
}
