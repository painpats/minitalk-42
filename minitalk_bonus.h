/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:12:19 by cbourre           #+#    #+#             */
/*   Updated: 2022/09/27 16:15:44 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft/libft.h"
# include <signal.h>
# include <sys/types.h>

//server_bonus
unsigned int	ft_bintoint(int *lenbin);
char			ft_bintochar(int*charbin);
unsigned int	ft_len_string(int signal);
void			ft_read_char(int signal, char *str, int len);
int				ft_messtocli(int signal);
void			ft_read_signal(int signal);
void			ft_end(char *str, int pid_client);

//client_bonus
void			ft_check_pid(char *prid);
void			ft_wrong_pid(void);
void			ft_send_strlen(unsigned int len, int prid);
void			ft_signal_received(int signal);
void			ft_chartobin(char *str, int prid);
void			ft_signal_received(int signal);

#endif
