/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:17 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/17 16:42:47 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	printf("0123456789aldfkgj;sldfkjglsdkj");
	printf("\n");
	printf("%s\n", ft_strchr("0123456789aldfkgj;sldfkjglsdkj", 'a'));
	printf("0123456789aldfkgj;sldfkjglsdkj");
	printf("\n");
	printf("%s\n", strchr("0123456789aldfkgj;sldfkjglsdkj", 'a'));
}
*/