/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:28:48 by cbourre           #+#    #+#             */
/*   Updated: 2022/09/26 13:45:14 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <sys/types.h>

//server
unsigned int	ft_bintoint(int *lenbin);
char			ft_bintochar(int*charbin);
unsigned int	ft_len_string(int signal);
void			ft_read_char(int signal, char *str, int len);
char			*ft_malloc_str(unsigned int len, char *str);
void			ft_read_signal(int signal);

//client
void			ft_check_pid(char *prid);
void			ft_wrong_pid(void);
void			ft_send_strlen(unsigned int len, int prid);
void			ft_chartobin(char *str, int prid);

#endif
