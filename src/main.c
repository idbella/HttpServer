/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 21:24:28 by superuser         #+#    #+#             */
/*   Updated: 2020/08/07 20:19:05 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int main()
{
    int                 fd;
    int                 client;
    struct sockaddr_in  ad;
    int                 len;

    len = sizeof(ad);
    fd = ft_tcpsocket(PORT);
    listen(fd, 100);
    while (1)
    {
        client = accept(fd, (SADRR)&ad, (socklen_t *)&len);
        if (client <= 0){
            perror("accept");
            break;
        }
        handler(client);
        close(client);       
    }
}
