/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_binto_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:13:08 by cbourre           #+#    #+#             */
/*   Updated: 2022/09/27 16:39:17 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//trans bin to int --> len of the string
unsigned int	ft_bintoint(int *lenbin)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (i < 32)
	{
		len = (len * 2) + lenbin[i];
		i++;
	}
	return (len);
}

//trans bin to char --> char in the string
char	ft_bintochar(int *charbin)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c = (c * 2) + charbin[i];
		i++;
	}
	return (c);
}

void	ft_end(char *str, int pid_client)
{	
	kill(pid_client, SIGUSR1);
	ft_printf("%s", str);
	free(str);
}
