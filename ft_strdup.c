/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:16:43 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/20 11:48:07 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (*str != '\0')
	{
		strlen++;
		str++;
	}
	return (strlen);
}

char	*ft_strdup(char *src)
{
	char	*str;
	char	*ret;
	int		len;

	len = 0;
	str = src;
	len = ft_strlen(str);
	str = malloc(sizeof (char) * len + 1);
	ret = str;
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (ret);
}

/*
#include <unistd.h>

void	ft_putstr(char *str)
{
	char	*i;

	i = str;
	while (*i != '\0')
	{
		write(1, i, 1);
		i++;
	}
}

int	main(void)
{
	static char	*src = "This is the string that is gonna be copied.";
	char		*str;

	str = ft_strdup(src);
	ft_putstr(str);
}
*/