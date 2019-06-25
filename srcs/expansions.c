/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:15:15 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/25 18:08:54 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*manage_expansions(char *input, char **env)
{
	char	*tilda;
	char	*dollar;

	tilda = manage_tilda(input, env);
	if (tilda && (dollar = manage_dollar(tilda, env)))
	{
		ft_memdel((void **)&tilda);
		return (dollar);
	}
	else if ((dollar = manage_dollar(input, env)))
		return (dollar);
	return (ft_strdup(input));
}
