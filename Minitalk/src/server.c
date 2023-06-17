/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:16:02 by eraccane          #+#    #+#             */
/*   Updated: 2023/06/06 12:16:05 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <stdio.h>

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	b;

	(void)context;
	if (b < 7)
	{
		c += (signal == SIGUSR1) << b;
		b++;
	}
	else
	{
		c += (signal == SIGUSR1) << b;
		if (c)
			write(1, &c, 1);
		else
		{
			kill(info->si_pid, SIGUSR1);
			ft_printf("\n");
		}
		c = 0;
		b = 0;
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Try ./server");
		return (0);
	}
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	ft_printf("pid: %u\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}
