/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 21:19:52 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/21 16:09:46 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test(char **argv, char **env)
{
	pid_t	p;
	int		status;

	if (argv && env)
	{}
	if ((p = fork()) == -1)
		return (printf("error fork()\n"));
	else if (!p)
	{
		int ret = execve(*argv, argv, env);
		if (-1 == ret)
			printf("error execve()\n");
		return (-1);
	}
	else
	{
		if (wait(&status) == -1)
			return (printf("error wait()\n"));
		printf("status: %d\n", status);
		return (0);
	}
	return (0);
}

int			main(int argc, char **argv, char **env)
{
	if (argc)
	{
		++argv;
		test(argv, env);
	}
	system("leaks a.out");
	return (0);
}
