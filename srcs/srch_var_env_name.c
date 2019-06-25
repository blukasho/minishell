/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srch_var_env_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:25:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/25 12:26:08 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*srch_var_env_name(char *name, char **env)
{
	int		name_len;
	char	*tmp;

	tmp = name;
	name_len = 0;
	while (is_var_name_symbol(*(tmp++)))
		++name_len;
	if (env && *env && name_len)
		while (*env)
		{
			if (!ft_strncmp(name, *env, name_len))
				return (*env + name_len + 1);
			++env;
		}
	return (NULL);
}
