/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:16:11 by eraccane          #+#    #+#             */
/*   Updated: 2023/06/06 12:16:12 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send_message(int pid, unsigned int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c / 2;
		i++;
		usleep(100);
	}
}

void	ft_sighandler(int a)
{
	a++;
	ft_printf("Messaggio ricevuto!\n");
	exit(0);
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("Error! Try ./client *PID* *TEXT*\n");
		return (0);
	}
	signal(SIGUSR1, ft_sighandler);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		ft_send_message(pid, av[2][i]);
		i++;
	}
	ft_send_message(pid, '\0');
	pause();
}
