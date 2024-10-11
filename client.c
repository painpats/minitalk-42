/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:10:31 by cbourre           #+#    #+#             */
/*   Updated: 2022/09/27 16:04:32 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

//send the len of the string in the parameters to the server
void	ft_send_strlen(unsigned int len, int prid)
{
	int	nbit;
	int	signal;

	nbit = 31;
	while (nbit >= 0)
	{
		signal = (len >> nbit) & 1;
		if (signal == 0)
		{
			if (kill(prid, SIGUSR1) == -1)
				ft_wrong_pid();
		}
		else
		{
			if (kill(prid, SIGUSR2) == -1)
				ft_wrong_pid();
		}
		nbit--;
		usleep(32);
	}
}

//send the translate char into binary to the server
void	ft_chartobin(char *str, int prid)
{
	int	i;
	int	nbit;
	int	signal;

	i = 0;
	while (str[i])
	{
		nbit = 7;
		while (nbit >= 0)
		{
			signal = str[i] & (1 << nbit);
			if (signal == 0)
				kill(prid, SIGUSR1);
			else
				kill(prid, SIGUSR2);
			nbit--;
			usleep(32);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error : Tree arguments needed\n", 2);
		exit (1);
	}
	ft_check_pid(argv[1]);
	if (argv[2][0] == '\0')
	{
		ft_putstr_fd("Error : The string is empty\n", 2);
		exit (1);
	}
	ft_send_strlen(ft_strlen(argv[2]), ft_atoi(argv[1]));
	ft_chartobin(argv[2], ft_atoi(argv[1]));
	return (0);
}
