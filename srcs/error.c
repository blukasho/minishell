/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:51:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/05 10:56:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		error_command_not_found(char *str)
{
	ft_printf("minishell: %s: command not found\n", str);
	return (0);
}

int		error_is_dir(char *str)
{
	ft_printf("minishell: %s: is directory\n", str);
	return (0);
}

int		error_no_such_file_or_directory(char *str)
{
	ft_printf("minishell: %s: no such file of directory\n", str);
	return (0);
}
