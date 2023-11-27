/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:11 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/27 11:03:21 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_checkset(char const *s1, char const *set)
{
	while (*set)
	{
		if (*s1 == *set)
			return (1);
		else
			set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*tmp1;
	char		*ret;
	size_t		len;
	size_t		i;

	len = 0;
	tmp1 = s1;
	while (*s1)
	{
		if (0 == ft_checkset(s1, set))
			len++;
		s1++;
	}
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (*tmp1)
	{
		if (0 == ft_checkset(tmp1, set))
			ret[i++] = *tmp1;
		tmp1++;
	}
	return (ret);
}

/*
#include <stdio.h>

int	main(void)
{
	static char	*str = "remove 'a', 'b', '.', ',', '~', 'z'";
	static char	*set = "ab.,~z";

	printf("\"%s\"", ft_strtrim(str, set));
}
*/