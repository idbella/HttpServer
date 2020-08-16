/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadstatic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:16:24 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/16 17:28:17 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char *ft_loadindex()
{
    
    return (ft_strdup("<h1>HttpServer v0.1</h1>"));
}

char *ft_loadstatic(char *file)
{
    int         fd;
    struct stat st;
    char        *content;

    if (ft_strequ(file, "/"))
        return (ft_loadindex());
    file = ft_join("./static/%s", file);
    ft_printf("requesting file %s\n", file);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return ft_strdup("404 not found");
    fstat(fd, &st);
    content = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (content == MAP_FAILED)
        return (NULL);
    return content;
}
