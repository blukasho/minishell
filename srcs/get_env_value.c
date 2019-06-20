/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:18:24 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/20 22:36:26 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_env_value(char **env, char *var)
{
	int		var_len;

	var_len = ft_strlen(var);
	while (env && *env)
		if (!ft_strncmp(var, *env, var_len) && (*env + var_len))
			return (*env + var_len);
		else
			++env;
	return (NULL);
}
