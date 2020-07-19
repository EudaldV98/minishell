/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:22:47 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/19 16:36:02 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error_cd(struct stat info, char *buff)
{
	if (S_ISREG(info.st_mode))
		ft_printf(1, "cd: not a directory: %s\n", buff);
	else
		ft_printf(1, "cd: no such file or directory: %s\n", buff);
}

void		ft_cd_home(char *buf)
{
	char	*dir;
	int		i;
	int		count;

	if (!(dir = malloc(sizeof(char) * BUFF_SIZE + 1)))
		return;
	dir = getcwd(dir, BUFF_SIZE);
	i = 0;
	count = 0;
	while (dir[i++])
		if (dir[i] == '/')
			count++;;
	while (count-- >= 2)
		chdir("..");
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
