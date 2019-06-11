/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:49:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/11 20:06:57 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_old_pwd(t_minishell *s, char *old_pwd)
{
	char	**env;
	char	*tmp;

	env = s->env;
	while (*env)
	{
		if (!ft_strncmp("OLDPWD=", *env, 7) && (tmp = *env))
		{
			*env = ft_strjoin("OLDPWD=", old_pwd);
			ft_strdel(&old_pwd);
			ft_strdel(&tmp);
			return (0);
		}
		++env;
	}
	env = s->env;
	tmp = ft_strjoin("OLDPWD=", old_pwd);
	s->env = add_string_to_arr(env, tmp);
	ft_strdel(&tmp);
	ft_strdel(&old_pwd);
	ft_str_del_arr(env);
	return (0);
}

static int	set_pwd(t_minishell *s)
{
	char	**env;
	char	*tmp;
	char	*new_pwd;

	env = s->env;
	if (!(tmp = getcwd(NULL, 0)))
			return (put_error("ERROR in set_pwd()", "getcwd()"));
	while (*env)
	{
		if (!ft_strncmp("PWD=", *env, 4) && !ft_strdel(&(*env)))
		{
			*env = ft_strjoin("PWD=", tmp);
			ft_strdel(&tmp);
			return (0);
		}
		++env;
	}
	env = s->env;
	new_pwd = ft_strjoin("PWD=", tmp);
	s->env = add_string_to_arr(env, new_pwd);
	ft_strdel(&new_pwd);
	ft_strdel(&tmp);
	ft_str_del_arr(env);
	return (0);
}

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
	set_old_pwd(s, old_pwd);
	set_pwd(s);
	return (0);
}
