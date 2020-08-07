/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readsocket.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:35:29 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/07 20:20:29 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char    *ft_readsocket(int fd)
{
	char			*str;
	fd_set			rfds;
	struct timeval	tv;
	int				retval;
	char			c;

	str = ft_strnew(0);
	while (1)
	{
		tv.tv_sec = 0;
		tv.tv_usec = 1000;
		FD_ZERO(&rfds);
		FD_SET(fd, &rfds);
		retval = select(fd + 1, &rfds, NULL, NULL, &tv);
		if (retval == -1){
			perror("select()");
			exit(EXIT_FAILURE);
		}
		if (retval)
		{
			read(fd, &c, 1);
			str = ft_join("%f%c", str, c);
			continue;
		}
		break;
	}
	return (str);
}
