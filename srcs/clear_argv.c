/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:54:13 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/01 15:02:56 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			clear_argv(char **argv)
{
	char	**tmp;

	tmp = argv;
	while (argv && *argv)
		ft_memdel((void **)&(*(argv++)));
	free(tmp);
	return (0);
}
