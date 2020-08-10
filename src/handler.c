/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:09:05 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/10 23:52:49 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

enum e_method get_request_method(char *str)
{
	if (ft_strequ(str, "GET"))
		return (GET);
	if (ft_strequ(str, "POST"))
		return (POST);
	if (ft_strequ(str, "DELETE"))
		return (DELETE);
	if (ft_strequ(str, "PUT"))
		return (PUT);
	return (-1);
}

char validate_http(char **parts)
{
	if (parts && parts[0] && parts[1] && parts[2])
	{
		if (get_request_method(parts[0]) < 0)
		{
			printf("%s: unsupported method\n", parts[0]);
			return (0);
		}
	}
	return (0);
}

char getroute(char **parts)
{
	return 1;
}

t_httprequest *parser(char *request_text)
{
	char			**lines;
	int				index;
	char			**parts;
	t_httprequest	*request;
	int				status;

	if (!(lines = ft_strsplit(request_text, '\n')))
		return (NULL);
	index = 1;
	parts = ft_strsplit(lines[0], ' ');

	if (validate_http(parts))
	{
		status = 0;
		while (lines && lines[index])
		{
			if (ft_strequ(lines[index], ""))
			{
				status = 1;
				break ;
			}
			printf("headers = %s\n", lines[index]);
			index++;
		}
		if (status)
		{
			request = ft_memalloc(sizeof(t_httprequest));
		}
	}
	return (request);
}

void    handler(int client)
{
	char	*response;
	char	*plain_text_request;

	if ((plain_text_request = ft_readsocket(client)))
	{
		response = "it's working";
		parser(plain_text_request);
		ft_printf_fd(
			client,
			"HTTP/1.1 200\nContent-Length: %d\nContent-Type: text/html\n\n%s",
			strlen(response),
			response
		);
	}
}
