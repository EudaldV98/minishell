/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:32:27 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/15 16:27:08 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <limits.h>
#define clear() printf("\033[H\033[J")

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

void	ft_error_cd(struct stat info, char *buff)
{
	if (S_ISREG(info.st_mode))
		ft_printf(1, "cd: not a directory: %s\n", buff);
	else
		ft_printf(1, "cd: no such file or directory: %s\n", buff);
}

void	ft_cd(char *buff)
{
	struct stat	info;
	int			i;
	int			o;
	char		*new_dir;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	buff[i] = '\0';
	i = 0;
	while (buff[i] && buff[i] == ' ')
		i++;
	if (stat(&buff[i], &info) == -1 || S_ISREG(info.st_mode))
	{
		ft_error_cd(info, &buff[i]);
		return;
	}
	chdir(&buff[i]);
}

int		ft_checkFlag(char *buff)
{

	return (0);
}

void	ft_echo(char *buff)
{
	char	*output;
	int		i;
	int		flag;
	
	i = 0;
	while (buff[i] && buff[i] == ' ')
		i++;
	ft_strlcpy(buff, &buff[i], ft_strlen(&buff[i]));
	flag = ft_strncmp(buff, "-n", 2) == 0 ? 1 : 0;
	if (!(output = (char *)malloc(sizeof(char) * ft_strlen(buff))))
		return ;
	ft_memset(output, 0, ft_strlen(buff));
	i = flag == 1 ? 2 : 0;
	while (buff[i] == ' ')
		i++;	
	ft_strlcpy(output, &buff[i], ft_strlen(&buff[i]) + 1);
	flag ? ft_printf(1, "%s", output) : ft_printf(1, "%s\n", output);
	free(output);
	output = NULL;
}

int     main(int ac, char **av, char **env)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		i;

	while(ft_strncmp(buff, "exit", ft_strlen("exit")))
	{
		ft_memset(buff, 0, sizeof(buff));
		init_shell();
		ret = read(0, buff, BUFF_SIZE);
		buff[ret] = '\0';
		i = 0;
		while (buff[i] && buff[i] == ' ')
			i++;
		if (!ft_strncmp(&buff[i], "cd ", ft_strlen("cd ")))
			ft_cd(&buff[i + 3]);
		if (!ft_strncmp(&buff[i], "echo ", ft_strlen("echo ")))
			ft_echo(&buff[i + 5]);
	}
	return (0);
}