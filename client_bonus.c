/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:28:45 by cbourre           #+#    #+#             */
/*   Updated: 2022/09/27 16:34:54 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_signal_received(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Message received 🤌 ✨\n", 1);
}

int	main(int argc, char **argv)
{
	int	pid_c;

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
	pid_c = getpid();
	ft_send_strlen(pid_c, ft_atoi(argv[1]));
	signal(SIGUSR1, ft_signal_received);
	ft_send_strlen(ft_strlen(argv[2]), ft_atoi(argv[1]));
	ft_chartobin(argv[2], ft_atoi(argv[1]));
	return (0);
}
