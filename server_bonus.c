/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:09:25 by cbourre           #+#    #+#             */
/*   Updated: 2022/09/27 14:53:53 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//get the len of the string
unsigned int	ft_len_string(int signal)
{
	static int		*sig;
	static int		nbit;
	unsigned int	len;

	if (sig == NULL)
		sig = ft_calloc(32, sizeof(unsigned int));
	if (nbit < 32)
	{
		if (signal == SIGUSR2)
			sig[nbit] = 1;
		nbit++;
	}
	if (nbit == 32)
	{
		len = ft_bintoint(sig);
		free(sig);
		sig = NULL;
		nbit = 0;
	}
	return (len);
}

//get each char of the tring
void	ft_read_char(int signal, char *str, int len)
{
	static int		*sig;
	static int		bit;
	static int		i;

	if (sig == NULL)
		sig = ft_calloc(8, sizeof(unsigned int));
	if (bit < 8)
	{
		if (signal == SIGUSR2)
			sig[bit] = 1;
		bit++;
	}
	if (bit == 8)
	{
		str[i] = ft_bintochar(sig);
		i++;
		if (i == len)
			i = 0;
		free(sig);
		sig = NULL;
		bit = 0;
	}
}

//get pid client
int	ft_messtocli(int signal)
{
	static int		*sig;
	static int		nbit;
	unsigned int	pid_client;

	if (sig == NULL)
		sig = ft_calloc(32, sizeof(unsigned int));
	if (nbit < 32)
	{
		if (signal == SIGUSR2)
			sig[nbit] = 1;
		nbit++;
	}
	if (nbit == 32)
	{
		pid_client = ft_bintoint(sig);
		free(sig);
		sig = NULL;
		nbit = 0;
		return (pid_client);
	}
	return (0);
}

//read each signal one by one and finaly print the string
void	ft_read_signal(int signal)
{
	static unsigned int		lbit;
	static unsigned int		cbit;
	unsigned int			len;
	static char				*str;
	int						pid_client;

	if (lbit <= 31)
		pid_client = ft_messtocli(signal);
	if (lbit >= 32 && lbit <= 63)
		len = ft_len_string(signal);
	if (lbit == 63)
		str = ft_calloc(len + 1, sizeof(char));
	else if (lbit > 63)
	{
		if (signal == SIGUSR1 || signal == SIGUSR2)
			ft_read_char(signal, str, len);
		if (++cbit == len * 8)
		{
			ft_end(str, pid_client);
			lbit = -1;
			cbit = 0;
		}
	}
	lbit++;
}

int	main(void)
{
	int	pid_a;

	pid_a = getpid();
	ft_printf("The Process ID is : %d\n", pid_a);
	signal(SIGUSR1, ft_read_signal);
	signal(SIGUSR2, ft_read_signal);
	while (1)
		continue ;
	return (0);
}
