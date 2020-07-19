/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:32:27 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/19 16:46:06 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define clear() printf("\033[H\033[J")
#include <limits.h>
 
void	init_shell(void)
{
	char	*dir;
	char	buff[PATH_MAX + 1];
	int		len;

	if (!(dir = malloc(sizeof(char) * BUFF_SIZE)))
		return;
	dir = getcwd(dir, BUFF_SIZE);
	len = ft_strlen(dir);
	while (len >= 0 && dir[len] != '/')
			len--;
	ft_printf(1, "" BOLDGREEN "➜ " RESET BOLDCYAN " %s " RESET, &dir[len + 1]);
	free(dir);
	dir = NULL;
}

int     main(int ac, char **av, char **env)
{
	int		ret;
	int		i;

	while(ft_strncmp(g_shell.buf, "exit", ft_strlen("exit")))
	{
		signal(SIGABRT, ft_get_signal);
		signal(SIGQUIT, ft_get_signal);
		signal(SIGINT, ft_get_signal);
		signal(SIGSEGV, ft_get_signal);
		signal(SIGTERM, ft_get_signal);
		init_shell();
		ret = read(0, g_shell.buf, BUFF_SIZE);
		g_shell.buf[ret] = '\0';
		i = 0;
		while (g_shell.buf[i] && g_shell.buf[i] == ' ')
			i++;
		if (!ft_strncmp(&g_shell.buf[i], "cd ", ft_strlen("cd ")))
			ft_cd(&g_shell.buf[i + 3]);
		else if (!ft_strncmp(&g_shell.buf[i], "echo ", ft_strlen("echo ")))
			ft_echo(&g_shell.buf[i + 5]);
		else if (!ft_strncmp(&g_shell.buf[i], "pwd", ft_strlen("pwd")))
			ft_pwd(&g_shell.buf[i + 3]);
		else if (!ft_strncmp(&g_shell.buf[i], "env", ft_strlen("env")))
			ft_env(&g_shell.buf[i + ft_strlen("env")], g_shell.env);
		else if (!ft_strncmp(g_shell.buf, "exit", ft_strlen("exit")))
			ft_printf(1, "minishell: command not found %s", g_shell.buf);
		free(g_shell.dir);
		g_shell.dir = NULL;
	}
	return (0);
}
