/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:53:37 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/10 20:11:36 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env(t_minishell *s)
{
	char	**env;

	env = s->env;
	while (*env)
		ft_printf("%s\n", *(env++));
	return (0);
}