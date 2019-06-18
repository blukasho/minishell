/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tilda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/18 16:35:50 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_home(char **env)
{
	if (env)
		while (*env)
			if (!ft_strncmp(*env, "HOME=", 5))
				return (*(env + 5));
			else
				++env;
	return (NULL);
}

static char	*get_result_string(char *input, char *home)
{
	char	*res;
	int		len_aft;
	int		len_bef;

	len_bef = 0;
	while (input[len_bef] != '~')
		++len_bef;
	len_aft = ft_strlen(input) - len_bef;
	res = ft_strnew((len_aft + len_bef + ft_stlen(home)));
	return (res);
}

char		*manage_tilda(char *input, char **env)
{
	char	*home;
	char	*tmp;

	if (env && (home = get_home(env)))
	{
		tmp = input;
		while (*tmp && *tmp != '~')
			++tmp;
		if (!*tmp || (*tmp == '~' && *(tmp + 1) == '~'))
			return (NULL);
		return (get_result_string(input, home));
	}
	return (NULL);
}
