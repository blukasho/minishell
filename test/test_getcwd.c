/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:35:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/24 14:25:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			main(void)
{
	char	*buf;

	if ((buf = getcwd(NULL, 0)))
		printf("%s\n", buf);
	system("leaks -q a.out");
	return (0);
}
