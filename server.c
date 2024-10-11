/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:09:25 by cbourre           #+#    #+#             */
/*   Updated: 2022/09/26 13:47:35 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

//malloc the len of the string
char	*ft_malloc_str(unsigned int len, char *str)
{
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		exit (1);
	return (str);
}

//read each signal one by one and finaly print the string
void	ft_read_signal(int signal)
{
	static unsigned int		lbit;
	static unsigned int		cbit;
	unsigned int			len;
	static char				*str;

	if (lbit <= 31)
		len = ft_len_string(signal);
	if (lbit == 31)
		str = ft_malloc_str(len, str);
	else if (lbit > 31)
	{
		if (signal == SIGUSR1 || signal == SIGUSR2)
			ft_read_char(signal, str, len);
		cbit++;
		if (cbit == len * 8)
		{
			str[len] = '\0';
			ft_printf("%s", str);
			free(str);
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
