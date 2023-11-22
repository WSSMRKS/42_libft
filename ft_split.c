/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:21:56 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/22 13:50:01 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

size_t	ft_strcount(char *str, char c)
{
	size_t	i;

	i = 0;
	str++;
	while (*str)
	{
		if (*str == c && *(str - 1) != c)
			i++;
		str++;
	}
	if (*str == '\0' && *(str - 1) != c)
		i++;
	return (i);
}

size_t	ft_strlen_split(char *str, char del)
{
	size_t	a;

	a = 0;
	while (*str != del && *str != '\0')
	{
		a++;
		str++;
	}
	return (a);
}

char	*ft_strdup_split(char *arr, char *s, char c, int *k)
{
	int		i;
	int		len;

	len = ft_strlen_split(&s[*k], c);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[*k] != c && s[*k] != '\0')
	{
		arr[i++] = s[*k];
		*k += 1;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**arr;
	int		i;
	int		k;

	k = 0;
	i = 0;
	count = ft_strcount((char *)s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
	{
		free((void *) arr);
		return (NULL);
	}
	while (count > 0)
	{
		if (s[k] == c)
			k++;
		else
		{
			arr[i] = ft_strdup_split(arr[i], (char *)s, c, &k);
			if (!arr)
				break ;
			i++;
			count--;
		}
	}
	if (count > 0)
		ft_free(arr);
	if (count == 0)
		arr[i] = NULL;
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
