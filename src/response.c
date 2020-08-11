/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 00:01:35 by sid-bell          #+#    #+#             */
/*   Updated: 2020/08/11 00:07:40 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_setheader(int client, char *name, char *value)
{
	ft_printf_fd(client, "%s: %s", name, value);
}

void	ft_setresponsestatus(int status, char *resonse)
{

}


