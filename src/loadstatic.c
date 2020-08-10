/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadstatic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:16:24 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/08 02:28:27 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char *ft_loadstatic(char *file)
{
    int         fd;
    struct stat st;
    char        *content;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return ft_strdup("404 not found");
    fstat(fd, &st);
    content = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (connect == MAP_FAILED)
        return (NULL);
    return connect;
}
