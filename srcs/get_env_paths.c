/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:58:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/05 10:02:30 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_env_paths(char **env)
{
	char	**env_paths;

	env_paths = NULL;
	while (*env && ft_strncmp(*env, "PATH", 4))
		++env;
	if (*env)
		env_paths = ft_strsplit(*env + 5, ':');
	return (env_paths);
}
