/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcpsocket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:16:41 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/07 20:21:25 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_tcpsocket(unsigned short port)
{
	int					fd;
	struct sockaddr_in	address;

	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (-1);
	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int))<0)
		return (-1);
	address.sin_port = htons(port);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	if (bind(fd, (struct sockaddr *)&address, (socklen_t)sizeof(address)) < 0)
		return (-1);
	return (fd);
}
