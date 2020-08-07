/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:09:05 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/07 20:21:00 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char    *parser(int client)
{
	char	*request;
	char	**lines;
	int		index;

	if ((request = ft_readsocket(client)))
	{
		lines = ft_strsplit(request, '\n');
		index = 1;
		while (lines && lines[index])
		{
			printf("headers = %s\n", lines[index]);
			index++;
		}
	}
	return (NULL);
}

void    handler(int client)
{
	char *response;

	response = "it'working";
	parser(client);
	ft_printf_fd(
		client,
		"HTTP/1.1 200\nContent-Length: %d\nContent-Type: text/html\n\n%s",
		strlen(response),
		response
	);
}
