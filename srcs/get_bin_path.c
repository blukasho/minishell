/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:17:29 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/03 13:16:28 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_bin_path(t_minishell *s)
{
	char	**paths;

	paths = s->bin_paths;
	if (paths)
	{}
	if (is_way(*(s->argv)))
		return (*(s->argv));
	return (NULL);
}
