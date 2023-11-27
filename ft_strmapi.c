/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:30:22 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/27 11:01:20 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

static size_t	ft_strlen(char *str)
{
	size_t	a;

	a = 0;
	while (*str)
	{
		a++;
		str++;
	}
	return (a);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	return (ret);
}

/*
static char	my_toupper(unsigned int i, char c)
{
	(void)i;
	return ((char)toupper((int)c));
}

int	main(void)
{
	char const	*s4 = "string to set to uppercase.1234567890";
	char		*mapres;

	mapres = ft_strmapi(s4, (char (*)(unsigned int, char))my_toupper);
	printf("%s\n\n", s4);
	printf("%s\n\n", mapres);
}
*/