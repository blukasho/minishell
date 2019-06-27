/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:07:11 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/27 17:11:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_env_var(char *input, char **env)
{
	int		len_var_name;

	len_var_name = 0;
	while (is_var_name_symbol(input[len_var_name]))
		++len_var_name;
	while (*env)
	{
		if (!ft_strncmp(input, *env, len_var_name) &&
			*(*env + len_var_name) == '=')
			return (1);
		++env;
	}
	return (0);
}

static char	*get_var_name(char *input)
{
	int		name_len;
	char	*var_name;

	name_len = 0;
	input = ft_strchr(input, DOLLAR) + 1;
	while (is_var_name_symbol(input[name_len]))
		++name_len;
	var_name = ft_strnew(name_len + 1);
	name_len = -1;
	while (is_var_name_symbol(input[++name_len]))
		var_name[name_len] = input[name_len];
	var_name[name_len] = '=';
	return (var_name);
}

static char	*add_env_val_to_input(char *input, char **env)
{
	char	*env_value;
	char	*var_name;
	char	*result;
	char	*tmp;

	var_name = get_var_name(input);
	env_value = get_env_value(env, var_name);
	ft_strdel(&var_name);
	result = ft_strnew((ft_strlen(input) + ft_strlen(env_value)));
	tmp = result;
	while (*input && *input != DOLLAR)
		*(tmp++) = *(input++);
	if (*input && *input == DOLLAR)
		++input;
	while (*input && is_var_name_symbol(*input))
		++input;
	while (*env_value)
		*(tmp++) = *(env_value++);
	while (*input)
		*(tmp++) = *(input++);
	return (result);
}

char		*manage_dollar(char *input, char **env)
{
	char	*new_input;
	char	*tmp;

	new_input = ft_strdup(input);
	if (!ft_strchr(new_input, DOLLAR))
		return (new_input);
	if (env && *env)
	{
		while (ft_strchr(new_input, DOLLAR))
		{
			if (has_env_var(ft_strchr(new_input, DOLLAR) + 1, env))
			{
				tmp = new_input;
				new_input = add_env_val_to_input(new_input, env);
				ft_strdel(&tmp);
			}
			else
				skip_var_name(new_input);
		}
	}
	else
		while (*new_input && ft_strchr(new_input, DOLLAR))
			skip_var_name(new_input);
	return (new_input);
}
