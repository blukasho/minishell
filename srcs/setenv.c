/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:28:29 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/20 14:41:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static int	check_format_error(char *env)
{
	char	*err = "use only uppercase letters and symbol '_' in KEY";

	while (*env && *env != '=')
	{
		if ((ft_isalpha(*env) && !ft_is_upper(*env)) ||
			(!ft_isalpha(*env) && *env != '_'))
			return (!put_error("setenv, ", err));
		++env;
	}
	if (!*env || *env != '=' || !*(env + 1))
		return (1);
	return (0);
}

int			minishell_setenv(t_minishell *s)
{
	char	**old_env;
	char	**argv;

	argv = s->argv;
	old_env = s->env;
	++argv;
	if (!*argv || *(argv + 1))
		return (put_error("setenv,",
				"need set argument in fomat KEY=VALUE"));
	if (check_format_error(*argv))
		return (put_error("setenv, not correct format", *argv));
	s->env = add_string_to_arr(old_env, *argv);
	ft_str_del_arr(old_env);
	return (0);
}
