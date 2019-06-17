/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:15:15 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/17 14:34:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*manage_tilda(char *input)
{
	if (input)
	{}
	return (ft_strdup(input));
}

static char	*manage_dollar(char *input)
{
	if (input)
	{}
	return (ft_strdup(input));
}

char		*manage_expansions(char *input)
{
	char	*tmp;

	tmp = input;
	input = manage_tilda(input);
	if (tmp)
		ft_strdel(&tmp);
	tmp = input;
	input = manage_dollar(input);
	if (tmp)
		ft_strdel(&tmp);
	return (input);
}
