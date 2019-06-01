/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:14:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/01 13:44:30 by blukasho         ###   ########.fr       */
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
}				t_minishell;

t_minishell	*get_t_minishell(char **env);

int			minishell(char **env);
int			print_start_msg(void);
int			clear_argv(char **argv);
int			check_builtins(t_minishell *s);
int			clear_t_minishell(t_minishell *s);

char		*read_line(void);

char		**get_argv(void);
char		**get_dup_string_arr(char **arr);

#endif
