/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:14:52 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/19 16:19:14 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_env(char *buf, char **env)
{
	int		i;

	i = 0;
	while (buf[i] == ' ')
		i++;
	if (buf[i] != '\n' || (buf[i] == '\n' && buf[i + 1] != '\0'))
	{
		if (i == 0)
			return ((void)ft_printf(1, "minishell: command not found env%s", buf));
		ft_printf(1, "env: take no argument\n");
		return ;
	}
	i = 0;
	while (env[i])
		ft_printf(1, "%s\n", env[i++]);
}
