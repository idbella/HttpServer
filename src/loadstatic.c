/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadstatic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:16:24 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/07 20:16:40 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char *ft_loadstatic(char *file)
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
