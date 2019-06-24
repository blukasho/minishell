/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:07:11 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/24 19:51:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_var_name_symbol(char c)
{
	if (ft_is_upper(c) || c == '_')
		return (1);
	return (0);
}

static char	*srch_var_name(char *input)
{
	char	*tmp;

	while (*input)
	{
		if (*input == DOLLAR && ++input)
		{
			tmp = input;
			while (*input && is_var_name_symbol(*input))
				++input;
			if (!*input || ft_is_space(*input))
				return (tmp);
		}
		if (*input)
			++input;
	}
	return (NULL);
}

static char	*srch_var_env_name(char *name, char **env)
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

static char	*get_new_input(char *input, char *var_name, char *var_env)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(ft_strlen(input) + ft_strlen(var_env));
	while (input != (var_name - 1))
		res[i++] = *(input++);
	while (*var_env)
		res[i++] = *(var_env++);
	while (*var_name && is_var_name_symbol(*var_name))
		++var_name;
	while (*var_name)
		res[i++] = *(var_name++);
	res[i] = '\0';
	return (res);
}

char		*manage_dollar(char *input, char **env)
{
	char	*var_name;
	char	*var_env;

	if (env && (var_name = srch_var_name(input)) && *var_name)
	{
		if ((var_env = srch_var_env_name(var_name, env)) && *var_env)
			return (get_new_input(input, var_name, var_env));
	}
	return (ft_strdup(input));
}
