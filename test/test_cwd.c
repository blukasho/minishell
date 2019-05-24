/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:30:25 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/24 14:33:51 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int			main(void)
{
	char	buf[4000];
	ssize_t	i;

	i = readlink("/proc/PID/cwd", buf, 4000);
	printf("%zd %s\n", i, buf);
	return (0);
}
