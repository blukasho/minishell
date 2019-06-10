/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:49:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/10 20:37:12 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_cd_errors(char *pathname)
{
	if (!pathname)
		return (1);
	if (access(pathname, F_OK) == -1 &&
			!put_error(pathname, "no such file or directory"))
		return (1);
	if (access(pathname, X_OK) == -1 &&
			!put_error(pathname, "permission denied"))
		return (1);
	return (0);
}

int			cd(t_minishell *s)
{
	char	**argv;
	char	*old_pwd;

	argv = s->argv;
	++argv;
	if (check_cd_errors(*argv))
		return (0);
	if (!(old_pwd = getcwd(NULL, 0)) && !put_error(*argv, "ERROR getcwd()"))
		return (0);
	if (chdir(*argv) == -1 && !put_error(*argv, "ERROR chdir()") &&
		!ft_strdel(&old_pwd))
		return (0);
//	set_pwd_env(s);
	//need set pwd && oldpwd env variables
	return (0);
}
