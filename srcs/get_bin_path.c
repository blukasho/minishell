/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:17:29 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/02 15:57:00 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_bin_path(t_minishell *s)
{
	char	**paths;

	paths = s->bin_paths;
	if (paths && *paths)
	{}
	return (NULL);
}
