/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:19:46 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/19 16:22:33 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_get_signal(int code)
{
	if (code == SIGINT)
		//Pas d'exit, relancer une affiche de prompt
	if (code == SIGQUIT)
		ft_printf(1, "exit: signal code %d\n", code);
	exit(code);
}
