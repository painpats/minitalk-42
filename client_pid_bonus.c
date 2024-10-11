/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_pid_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:05:38 by cbourre           #+#    #+#             */
/*   Updated: 2022/09/27 16:18:31 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//check if the pid is valid
void	ft_check_pid(char *prid)
{
	int	i;

	i = 0;
	while (prid[i] >= '0' && prid[i] <= '9')
		i++;
	if (ft_atoi(prid) < 0 || prid[i] != '\0')
	{
		ft_putstr_fd("Error : PID must be numeral and positive\n", 2);
		exit (1);
	}
}

void	ft_wrong_pid(void)
{
	ft_putstr_fd("Error : Wrong PID\n", 2);
	exit (1);
}
