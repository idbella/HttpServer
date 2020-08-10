/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readsocket.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:35:29 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/08 02:02:25 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_buffer_ready(int fd, int timeout)
{
	struct timeval	tv;
	int				retval;
	fd_set			rfds;

	tv.tv_sec = timeout;
	tv.tv_usec = 1000;
	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);
	if ((retval = select(fd + 1, &rfds, NULL, NULL, &tv)) == -1)
	{
		perror("select()");
		exit(EXIT_FAILURE);
	}
	return (retval);
}

char    *ft_readsocket(int fd)
{
	char			*str;
	int				character;
	int				timeout;

	str = ft_strnew(0);
	timeout = 5;
	while (1)
	{
		if (ft_buffer_ready(fd, timeout))
			if (read(fd, &character, 1) > 0)
			{
				str = ft_join("%f%c", str, character);
				timeout = 0;
				continue;
			}
		break;
	}
	return (str);
}
