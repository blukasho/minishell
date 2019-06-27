/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:14:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/27 09:28:38 by blukasho         ###   ########.fr       */
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

t_minishell		*get_t_minishell(char **env);
void			execsignalhandler(int sig);
void			setsignalhandler(int sig);
int				skip_var_name(char *input);
int				minishell(char **env);
int				is_var_name_symbol(char c);
int				run_minishell(t_minishell *s);
int				print_welcome(void);
int				print_start_msg(void);
int				clear_argv(char ***argv);
int				check_builtins(t_minishell *s);
int				check_errors_minishell(t_minishell *s);
int				check_exit(t_minishell *s);
int				clear_t_minishell(t_minishell *s);
int				is_way(char *str);
int				is_dir(char *str);
int				is_file(char *filename);
int				error_command_not_found(char *str);
int				put_error(char *file, char *err);
int				cd(t_minishell *s);
int				echo(t_minishell *s);
int				env(t_minishell *s);
int				minishell_unsetenv(t_minishell *s);
int				minishell_setenv(t_minishell *s);
char			*get_home(char **env);
char			*read_line(void);
char			*srch_var_env_name(char *name, char **env);
char			*manage_dollar(char *input, char **env);
char			*manage_tilda(char *input, char **env);
char			*get_env_value(char **env, char *var);
char			*manage_expansions(char *input, char **env);
char			***get_argv(char **env);
char			**get_env_paths(char **env);
char			**get_bin_paths(t_minishell *s);
char			**get_dup_string_arr(char **arr);
char			**add_string_to_arr(char **arr, char *path);

#endif
