/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:32:27 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/14 18:29:03 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <limits.h>
#define clear() printf("\033[H\033[J")

void	init_shell(void)
{
	char	*dir;
	char	buff[PATH_MAX + 1];
	char	*curr_dir;
	dir = getcwd(buff, PATH_MAX + 1);
	if (!(curr_dir = malloc(sizeof(char) * ft_strlen(dir) + 1))
	ft_printf(1, "" BOLDGREEN "➜ " RESET BOLDCYAN " %s " RESET, dir);
}

int     main(int ac, char **av, char **env)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while(ft_strncmp(buff, "exit", ft_strlen("exit")))
	{
		init_shell();
		ret = read(0, buff, BUFF_SIZE + 1);
		
		//handle args
	}
	return (0);
}