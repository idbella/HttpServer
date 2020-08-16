/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:30:15 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/16 17:18:56 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <stdio.h>
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/select.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>

# define PORT 8081
# define SADRR struct sockaddr *

enum e_method
{
	NONE = -1,
	GET,
	POST,
	DELETE,
	PUT
};

typedef struct	s_httprequest
{
	char			*http_version;
	char			*route;
	enum e_method	method;
	char			*body;
}				t_httprequest;

typedef struct	s_client
{
	t_httprequest	request;
	int				headers_sent;
}				t_client;

int		ft_tcpsocket(unsigned short port);
char    *ft_readsocket(int fd);
void    handler(int client);
char    *ft_loadstatic(char *file);

#endif
