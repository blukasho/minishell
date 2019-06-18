/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:15:15 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/18 15:25:23 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*manage_expansions(char *input, char **env)
{
	char	*tilda;

	tilda = manage_tilda(input, env);
	if (tilda)
		return (tilda);
	return (ft_strdup(input));
}
