/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:29:45 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/19 16:33:47 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_pwd_error(char *buf, int error)
{
	if (error == 0)
		ft_printf(1, "pwd: too many arguments\n");
	else if (error == 1)
		ft_printf(1, "minishell: command not found pwd%s", buf);
}

void		ft_pwd(char *buf)
{
	char	*pwd;
	int		i;

	i = 0;
	while (buf[i] == ' ')
		i++;
	if (buf[i] != '\n')
	{
		if (i != 0)
			ft_pwd_error(buf, 0);
		else
			ft_pwd_error(buf, 1);
		return;
	}
	if (!(pwd = malloc(sizeof(char) * BUFF_SIZE + 1)))
		return;
	pwd = getcwd(pwd, BUFF_SIZE);
	pwd[BUFF_SIZE] = '\0';
	ft_printf(1, "%s\n", pwd);
	free(pwd);
	pwd = NULL;
}
