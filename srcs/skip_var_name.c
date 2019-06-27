/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_var_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:22:02 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/27 17:52:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			skip_var_name(char *input)
{
	if (!*input)
		return (0);
	input = ft_strchr(input, DOLLAR);
	while (*input && (is_var_name_symbol(*input) || *input == DOLLAR))
		ft_memmove(input, input + 1, ft_strlen(input));
	return (0);
}
