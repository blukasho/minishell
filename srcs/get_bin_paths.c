/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:46:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/05 22:56:26 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static char	**add_path_to_arr(char **arr, char *path)
{
	int		len;
	char	**tmp;

	tmp = arr;
	if ((len = 2) && arr)
	{
		while (*arr && ++len)
			++arr;
		if ((arr = (char **)malloc(len *sizeof(char *))))
		{
			len = -1;
			while (tmp[++len])
				arr[len] = tmp[len];
			arr[len++] = ft_strdup(path);
			arr[len] = NULL;
		}
	}
	else if ((arr = (char **)malloc(len * sizeof(char *))))
	{
		*arr = ft_strdup(path);
		*(arr + 1)= NULL;
		return (arr);
	}
	return (NULL);
}

static char	*get_bin_in_path(char *path, char *bin)
{
	if (path && bin)
	{}
	return (NULL);
}

char		**get_bin_paths(t_minishell *s)
{
	char	**env_paths;
	char	**tmp_bin_paths;
	char	*tmp_str;

	if (is_way(*(s->argv)))
		return (add_path_to_arr(s->bin_paths, *(s->argv)));
	env_paths = s->env_paths;
	while (*env_paths)
	{
		tmp_bin_paths = s->bin_paths;
		if ((tmp_str = get_bin_in_path(*env_paths, *(s->argv))))
		{
			s->bin_paths = add_path_to_arr(s->bin_paths, tmp_str);
			if (tmp_bin_paths)
				clear_argv(&tmp_bin_paths);
			if (tmp_str)
				ft_strdel(&tmp_str);
		}
		++env_paths;
	}
	return (s->bin_paths);
}
