/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:09:05 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/11 00:30:08 by sid-bell         ###   ########.fr       */
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
	return (NONE);
}

enum e_method validate_http(char **parts)
{
	enum e_method method;

	method = NONE;
	if (parts && parts[0] && parts[1] && parts[2])
	{
		if ((method = get_request_method(parts[0])) == NONE)
		{
			printf("%s: unsupported method\n", parts[0]);
			return (method);
		}
	}
	return (method);
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

	if (!(lines = ft_strsplit(request_text, '\n')))
		return (NULL);
	index = 1;
	parts = ft_strsplit(lines[0], ' ');
	request = NULL;
	if (validate_http(parts) != NONE)
	{
		request = ft_memalloc(sizeof(t_httprequest));
		request->http_version = parts[2];
		request->method = get_request_method(parts[0]);
		request->route = parts[1];
	}
	return (request);
}

void    handler(int client_fd)
{
	char		*response;
	char		*plain_text_request;
	t_client	client;

	client.headers_sent = 2;
	if ((plain_text_request = ft_readsocket(client_fd)))
	{
		if (parser(plain_text_request))
		{
			response = "it's working";
			ft_printf_fd(
				client_fd,
				"HTTP/1.1 200\nContent-Length: %d\nContent-Type: text/html\n\n%s",
				strlen(response),
				response
			);
		}
		else
		{
			response = "bad request";
			ft_printf_fd(
				client_fd,
				"HTTP/1.1 400\nContent-Length: %d\nContent-Type: text/html\n\n%s",
				strlen(response),
				response
			);
		}
	}
}
