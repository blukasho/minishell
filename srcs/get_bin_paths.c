/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 13:43:27 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/02 13:49:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_bin_paths(char **env)
{
	char	**bin_paths;

	bin_paths = NULL;
	while (*env && ft_strncmp(*env, "PATH", 4))
		++env;
	if (*env)
		bin_paths = ft_strsplit(*env + 5, ':');
	return (bin_paths);
}
