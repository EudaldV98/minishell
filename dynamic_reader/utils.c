/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <lmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:00:40 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/21 11:39:01 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strncat(char *dest, const char c, int nb)
{
	int	i;
	int	dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (i < nb)
	{
		dest[dest_size] = c;
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}
