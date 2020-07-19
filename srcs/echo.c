/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:21:23 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/19 16:22:26 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
