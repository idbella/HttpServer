/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 21:24:28 by superuser         #+#    #+#             */
/*   Updated: 2020/08/06 15:01:12 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <fcntl.h>

#define PORT 8081
# define SADRR struct sockaddr *

int ft_creat_server(struct sockaddr_in *ad)
{
    int fd;
    int opt;

    opt = 1;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0){
        perror("socket ");
    }
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(1);
    } 
    ad->sin_family = AF_INET;
    ad->sin_port = htons(PORT);
    ad->sin_addr.s_addr = INADDR_ANY;
    if (bind(fd, (SADRR)ad, (socklen_t)sizeof(*ad)) < 0){
        perror("bind ");
        exit(1);
    }
    return (fd);
}


char *ft_get(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return ft_strdup("404 not found");
    char *line;
    char *str = NULL;

    while (get_next_line(fd, '\n', &line) > 0)
    {
        if (!str)
            str = ft_strdup(line);
        else
            str = ft_join("%s\n%s", str, line);
        ft_strdel(&line);
    }
    return str;
}

char    *ft_read(int fd, int t){

    char *str;
   fd_set rfds;
    struct timeval tv;
    int retval;
    char c;
    str = ft_strnew(0);

    while (1)
    {
        tv.tv_sec = t;
        tv.tv_usec = 0;
           FD_ZERO(&rfds);
            FD_SET(fd, &rfds);
        retval = select(fd + 1, &rfds, NULL, NULL, &tv);
        if (retval == -1){
            perror("select()");
            exit(EXIT_FAILURE);
        } else if (retval) {
            read(fd, &c, 1);
            str = ft_join("%f%c", str, c);
            continue;
        }
        break;
    }
    return str;
}


int main()
{
    int fd;
    int client;
    struct sockaddr_in ad;
    int len = sizeof(ad);

    fd = ft_creat_server(&ad);
    listen(fd, 100);
    while (1)
    {
        client = accept(fd, (SADRR)&ad, (socklen_t *)&len);
        if (client <= 0){
            perror("accept");
            break;
        }
        ft_printf("\nclient reached\n");
        char *req; 
        get_next_line(client, '\n', &req);
        ft_printf("rq = %s\n", req);
        char *route = ft_strsplit(req, ' ')[1];
        route = ft_join(".%f", route);
        ft_printf("rt = %s\n", route);
        char *res = ft_get(route);
        ft_printf("<%s>", res);
        ft_printf_fd(
            client,
            "HTTP/1.1 200\nContent-Length: %d\nContent-Type: text/html\n\n%s",
            strlen(res),
            res
        );
        close(client);       
    }
    
}