/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:30:15 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/07 20:20:34 by sid-bell         ###   ########.fr       */
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

# define PORT 8081
# define SADRR struct sockaddr *

int		ft_tcpsocket(unsigned short port);
char    *ft_readsocket(int fd);
void    handler(int client);
char    *ft_loadstatic(char *file);

#endif
