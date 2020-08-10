/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 21:24:28 by superuser         #+#    #+#             */
/*   Updated: 2020/08/08 22:09:11 by sid-bell         ###   ########.fr       */
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
    if ((fd = ft_tcpsocket(PORT)) < 0)
        return (EXIT_FAILURE);
    printf("server running on http://localhost:%d\n", PORT);
    listen(fd, 100);
    while (1)
    {
        client = accept(fd, (SADRR)&ad, (socklen_t *)&len);
        if (client <= 0)
        {
            perror("accept");
            break ;
        }
        handler(client);
        close(client);       
    }
    return (EXIT_SUCCESS);
}
