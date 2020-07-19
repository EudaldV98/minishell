/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:37:35 by jvaquer           #+#    #+#             */
/*   Updated: 2020/07/19 16:33:31 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdarg.h>
# include <stdio.h>
# include <signal.h>
# include "../includes/ft_printf.h"
# include "../libft/libft/libft.h"

# define 		BUFF_SIZE 2048
# define 		S_QUOTE 39

typedef struct	s_minishell
{
	char	buf[BUFF_SIZE + 1];
	char	*output;
	char	*dir;
	char	**env;
	int		i;
}					t_minishell;

t_minishell		g_shell;

void			ft_env(char *buf, char **env);
void			ft_get_signal(int code);
void			ft_cd(char *buff);
void			ft_echo(char *buff);
void			ft_pwd(char *buf);


#endif
