/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:06:31 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/22 20:28:01 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_free(char **tofree)
{
	int	i;

	if (!tofree)
		return ;
	i = 0;
	while (tofree[i])
	{
		free((void *)tofree[i]);
		i++;
	}
	free((void *)tofree);
	return ;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (len > 0)
	{
		sub[i] = s[start];
		i++;
		start++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen_split(char *str, int mode, char del)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	if (mode == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != del && (str[i -1] == del || i == 0))
				a++;
			i++;
		}
		return (a);
	}
	else 
	{
		while (*str != del && *str != '\0')
		{
			str++;
			a++;
		}
		return (a);
	}
}

char	**ft_split(char const *s, char c)
{
	int		strings;
	int		len;
	char	**arr;
	int		i;
	int		k;

	strings = ft_strlen_split((char *)s, 1, c);
	arr = malloc(sizeof(char *) * (strings + 1));
	if (!arr)
	{
		free(arr);
		return (NULL);
	}
	i = 0;
	len = 0;
	k = 0;
	while (strings > 0)
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
		{
			len = ft_strlen_split((char *)&s[i], 2, c);
			arr[k] = ft_substr(s, i, len);
			if (arr[k] == NULL)
				ft_free(arr);
			i += len; 
			k++;
			strings--;
		}
	}
	if (strings == 0)
		arr[k] = NULL;
	return (arr);
}

int	main(void)
{
 	static char	*test = "This.is.the first test.of...........my.new..........split function";
	static char	c = '.';
	char		**split;
	size_t		i;

	i = 0;
	split = ft_split(test, c);
	while (split[i] != NULL)
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_free(split);
	return (0);
}

