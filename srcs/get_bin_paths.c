/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:46:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/11 13:46:55 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			*add_path_to_bin(char *path, char *bin)
{
	char			*res;
	char			*tmp;

	if (!(tmp = ft_strjoin(path, "/")))
		return (NULL);
	if (!(res = ft_strjoin(tmp, bin)) && !ft_strdel(&tmp))
		return (NULL);
	ft_strdel(&tmp);
	return (res);
}

static char			*get_bin_in_path(char *path, char *bin)
{
	DIR				*dir;
	struct dirent	*file;

	if (!(dir = opendir(path)))
		return (NULL);
	while ((file = readdir(dir)))
		if (!ft_strcmp(file->d_name, bin))
		{
			closedir(dir);
			return (add_path_to_bin(path, bin));
		}
	if (dir)
		closedir(dir);
	return (NULL);
}

char				**get_bin_paths(t_minishell *s)
{
	char			**env_paths;
	char			**tmp_bin_paths;
	char			*tmp_str;

	if (is_way(*(s->argv)) && is_file(*(s->argv)))
		return (add_string_to_arr(s->bin_paths, *(s->argv)));
	env_paths = s->env_paths;
	while (*env_paths)
	{
		tmp_bin_paths = s->bin_paths;
		if ((tmp_str = get_bin_in_path(*env_paths, *(s->argv))))
		{
			s->bin_paths = add_string_to_arr(s->bin_paths, tmp_str);
			if (tmp_bin_paths)
				clear_argv(&tmp_bin_paths);
			if (tmp_str)
				ft_strdel(&tmp_str);
		}
		++env_paths;
	}
	return (s->bin_paths);
}
