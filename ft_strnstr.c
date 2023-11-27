/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:21:31 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/27 11:02:40 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			i;
	int			k;
	int			l_tmp;

	if (*little == '\0')
		return ((char *)big);
	while (len > 0)
	{
		if (*big == *little)
		{
			i = 0;
			k = 0;
			l_tmp = len;
			while (l_tmp > 0 && big[i] == little[k] && big[i++] && little[k++])
				l_tmp--;
			if (little[k] == '\0')
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}

/*
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("--------------\n");
	printf("%s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("--------------\n");
	printf("%s\n", strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("--------------\n");
}
*/