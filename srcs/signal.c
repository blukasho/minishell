/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:37:45 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/24 18:40:56 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setsignalhandler(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		print_start_msg();
		signal(SIGINT, setsignalhandler);
	}
}

void	execsignalhandler(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		signal(SIGINT, setsignalhandler);
	}
}
