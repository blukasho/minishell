/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:01:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/27 18:00:28 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			run_minishell(t_minishell *s)
{
	char	**bin_paths;
	int		status;
	pid_t	pid;

	bin_paths = s->bin_paths;
	if (access(*bin_paths, X_OK) && !put_error("ERROR", "permission denied"))
		return (1);
	pid = fork();
	signal(SIGINT, execsignalhandler);
	if (pid == -1)
		put_error("ERROR", "fork()");
	else if (pid == 0 && execve(*bin_paths, s->argv, s->env))
		exit(put_error("ERROR", "execve()"));
	else
		wait(&status);
	return (1);
}
