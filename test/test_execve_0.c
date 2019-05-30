/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execve_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 22:13:40 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/29 22:37:35 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int			main(int argc, char **argv, char **env)
{
	if (argc && argv && env)
	{
		while (*argv)
			ft_printf("%s\n", *(argv++));
		ft_printf("<<<--->>>\n");
		while (*env)
			ft_printf("%s\n", *(env++));
	}
}
