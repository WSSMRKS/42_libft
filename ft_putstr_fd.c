/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:44:23 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/23 18:57:23 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int		strlen;
	int		i;

	i = 0;
	strlen = 0;
	while (s[i] != '\0')
	{
		strlen++;
		i++;
	}
	write(fd, s, strlen);
}
