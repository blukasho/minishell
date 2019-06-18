/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:14:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/18 18:08:24 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MINISHELL_START_MSG "$>"
# define TILDA '~'
# define DOLLAR '$'

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct	s_minishell
{
	char		**env;
	char		**argv;
	char		**env_paths;
	char		**bin_paths;
}				t_minishell;

t_minishell	*get_t_minishell(char **env);

int			minishell(char **env);
int			run_minishell(t_minishell *s);
int			print_welcome(void);
int			print_start_msg(void);
int			clear_argv(char ***argv);
int			check_builtins(t_minishell *s);
int			check_errors_minishell(t_minishell *s);
int			check_exit(t_minishell *s);
int			clear_t_minishell(t_minishell *s);
int			is_way(char *str);
int			is_dir(char *str);
int			is_file(char *filename);

int			error_command_not_found(char *str);
int			put_error(char *file, char *err);

int			cd(t_minishell *s);
int			echo(t_minishell *s);
int			env(t_minishell *s);
int			minishell_unsetenv(t_minishell *s);
int			minishell_setenv(t_minishell *s);

char		*read_line(void);
char		*manage_dollar(char *input, char **env);
char		*manage_tilda(char *input, char **env);
char		*manage_expansions(char *input, char **env);
char		**get_argv(char **env);
char		**get_env_paths(char **env);
char		**get_bin_paths(t_minishell *s);
char		**get_dup_string_arr(char **arr);
char		**add_string_to_arr(char **arr, char *path);

#endif
