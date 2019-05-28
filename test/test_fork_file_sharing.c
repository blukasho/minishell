/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork_file_sharing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:16:45 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/26 15:12:01 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int			main(int argc, char **argv)
{
	int		fd, flags;
	char	buf[] = "/tmp/XXXXXX";

	setbuf(stdout, NULL);
	fd = mkstemp(buf);
	if (fd == -1)
		return (printf("ERROR mkstemp\n"));	
	printf("File  offset before fork(): %lld\n", (long long) lseek(fd, 0, SEEK_CUR));
	flags = fcntl(fd, F_GETFL);
	if (flags == -1)
		return (printf("ERROR fcntl F_GETFL\n"));
	printf("O_APPEND flag before fork() is: %s\n", (flags & O_APPEND) ? "on" : "off");

	switch (fork())
	{
		case -1:
			return (printf("ERROR fork\n"));
		case 0:
			if (lseek(fd, 1000, SEEK_SET) == -1)
				return (printf("ERROR lseek"));
			flags = fcntl(fd, F_GETFL);
			if (flags == -1)
				return (printf("ERROR fcntl - F_GETFL\n"));
			flags |= O_APPEND;
			if (fcntl(fd, F_SETFL, flags) == -1)
				return (printf("ERROR fcntl - F_SETFL\n"));
			return (0);
		default:
			if (wait(NULL) == -1)
				return (printf("ERROR wait()\n"));
			printf("Child has exited\n");
			printf("File offset in parent: %lld\n", (long long)lseek(fd, 0, SEEK_CUR));
			flags = fcntl(fd, F_GETFL);
			if (flags == -1)
				return (printf("ERROR fcntl - F_GETFL"));
			printf("O_APPEND flag in parent s: %s\n", (flags & O_APPEND) ? "on" : "off");
	}
	return (0);
}
