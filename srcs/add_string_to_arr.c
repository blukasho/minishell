/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string_to_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:45:34 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/21 08:56:34 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**add_string_to_arr(char **arr, char *path)
{
	int				len;
	char			**tmp;

	tmp = arr;
	if ((len = 2) && arr)
	{
		while (*arr && ++len)
			++arr;
		if ((arr = (char **)malloc(len * sizeof(char *))))
		{
			len = -1;
			while (tmp[++len])
				arr[len] = ft_strdup(tmp[len]);
			arr[len++] = ft_strdup(path);
			arr[len] = NULL;
		}
		return (arr);
	}
	else if ((arr = (char **)malloc(len * sizeof(char *))))
	{
		*arr = ft_strdup(path);
		*(arr + 1) = NULL;
		return (arr);
	}
	return (NULL);
}
