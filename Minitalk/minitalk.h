/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:28:36 by eraccane          #+#    #+#             */
/*   Updated: 2023/06/06 12:28:38 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "ft_printf/includes/ft_printf.h"

void	ft_handler(int signal, siginfo_t *info, void *context);
void	ft_send_message(int pid, unsigned int c);
void	ft_sighandler(int a);

#endif
