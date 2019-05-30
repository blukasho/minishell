/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 21:19:52 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/29 22:42:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int			main(int argc, char **argv, char **env)
{
	char	*argVec[] = {"arg", "arg", NULL};
	char	*envVec[] = {"PWD=/", "HELLP", NULL};

	if (argc && argv && env && *envVec)
	{}

	argVec[0] = argv[1];

	execve(argv[1], argVec, envVec);
	ft_printf("ERROR\n");
	return (0);
}
