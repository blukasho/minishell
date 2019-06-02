/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:14:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/02 15:38:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MINISHELL_START_MSG "$>"

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct	s_minishell
{
	char		**env;
	char		**argv;
	char		**bin_paths;
	char		*bin_path;
}				t_minishell;

t_minishell	*get_t_minishell(char **env);

int			minishell(char **env);
int			print_start_msg(void);
int			clear_argv(char **argv);
int			check_builtins(t_minishell *s); //may be delete
int			check_exit(t_minishell *s);
int			clear_t_minishell(t_minishell *s);

int			error_command_not_found(t_minishell *s);

char		*read_line(void);
char		**get_argv(void);
char		**get_bin_paths(char **env);
char		*get_bin_path(t_minishell *s);
char		**get_dup_string_arr(char **arr);

#endif
