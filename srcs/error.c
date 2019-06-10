/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:51:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/10 17:14:09 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_errors_minishell(t_minishell *s)
{
	if (is_dir(*(s->argv)) && !put_error(*(s->argv), "is directory"))
		return (1);
	if (!(s->bin_paths) && !is_file(*(s->argv)) &&
		!put_error(*(s->argv), "no such file of directory"))
		return (1);
	return (0);
}

int		put_error(char *file, char *err)
{
	ft_printf("minishell: %s %s\n", file, err);
	return (0);
}
