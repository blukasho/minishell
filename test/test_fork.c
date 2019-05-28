/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:07:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/26 12:46:31 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int idata = 111;

int			main(int argc, char **argv)
{
	int		istack = 222;
	pid_t	childPid = 0;

//	switch (childPid = fork())
//	{
//		case -1:
//			return (printf("error fork\n"));
//		case 0:
//			idata *= 3;
//			istack *=3;
//			break;
//		default:
//			write(1, "default\n", 8);
//			sleep(1);
//			break;
//	}
	while (childPid != -1)
	{
		printf("childPid = %ld\n", (long)childPid);
		childPid = fork();
		sleep(10);
	}
	printf("PID=%ld %s idata=%d istack=%d, childPid = %ld\n", (long)getpid(), (childPid == 0) ? "(child) " : "(parent)", idata, istack, (long)childPid);
	return (0);
}
