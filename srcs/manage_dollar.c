/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:07:11 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/25 17:37:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char	*skip_var_name(char *input)
{
	while (input && *input && !is_var_name_symbol(*input))
		++input;
	while (input && *input && is_var_name_symbol(*input))
		++input;
	return (input);
}

char		*manage_dollar(char *input, char **env)
{
	char	*var_name;
	char	*var_env;
	char	*tmp_input;
	char	*new_input;

	tmp_input = NULL;
	new_input = NULL;
	while (*input && (var_name = srch_var_name(input)) && *var_name)
	{
		if (env && (var_name = srch_var_name(input)) && *var_name)
		{
			if ((var_env = srch_var_env_name(var_name, env)) && *var_env)
			{
				if (new_input && (tmp_input = new_input))
				{
					new_input = get_new_input(new_input, var_name, var_env);
					if (tmp_input)
						ft_strdel(&tmp_input);
				}
				else
					new_input = get_new_input(input, var_name, var_env);
			}
			else
				input = skip_var_name(input);
		}
		input = skip_var_name(input);
	}
	return ((new_input ? new_input : ft_strdup(tmp_input)));
}
