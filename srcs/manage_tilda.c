/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tilda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/20 18:56:19 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_home(char **env)
{
	if (env)
		while (*env)
		{
			if (!ft_strncmp(*env, "HOME=", 5))
				return (*env + 5);
			else
				++env;
		}
	return (NULL);
}

static char	*get_result_string(char *input, char *home)
{
	char	*res;
	int		len_aft;
	int		len_bef;

	len_bef = 0;
	while (input[len_bef] != TILDA)
		++len_bef;
	len_aft = ft_strlen(input) - len_bef;
	res = ft_strnew((len_aft + len_bef + ft_strlen(home)));
	len_bef = 0;
	while (*input != TILDA)
		res[len_bef++] = *(input++);
	while (*home)
		res[len_bef++] = *(home++);
	while (*(++input))
		res[len_bef++] = *input;
	return (res);
}

char		*manage_tilda(char *input, char **env)
{
	char	*home;
	char	*tmp;

	if (env && (home = get_home(env)))
	{
		tmp = input;
		while (*tmp && *tmp != TILDA)
			++tmp;
		if (!*tmp || (*tmp == TILDA && *(tmp + 1) == TILDA))
			return (NULL);
		return (get_result_string(input, home));
	}
	return (NULL);
}
