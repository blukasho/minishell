/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 09:52:23 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/13 14:45:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			print_start_msg(void)
{
	char	*path;

	if ((path = getcwd(NULL, 0)))
	{
		ft_printf("minishell %s:", path);
		ft_strdel(&path);
	}
	ft_printf("%s", MINISHELL_START_MSG);
	return (0);
}

int			print_welcome(void)
{
	int		i;
	
	i = 83;
	while (--i)
		ft_printf("#");
	ft_printf("\n#%50s%30c#\n#%80c#\n#%-80s#\n", "Welcome to minishell!!!", ' ',
			' ', "Created by blukasho");
	ft_printf("#%-80s#\n#%80c#\n#%50s%30c#\n", "https://github.com/blukasho",
			' ', "As beautiful as a shell", ' ');
	i = 83;
	while (--i)
		ft_printf("#");
	ft_printf("\n\n");
	return (0);
}
