/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:46:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/05 14:58:57 by blukasho         ###   ########.fr       */
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

char		**get_bin_paths(t_minishell *s)
{
	if (is_way(*(s->argv)))
		return (add_path_to_arr(s->bin_paths, *(s->argv)));
	//need write checks all bin paths
	return (NULL);
}
