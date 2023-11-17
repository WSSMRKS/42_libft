/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:43:49 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/17 16:44:17 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (*(char *)s1 == *(char *)s2 && *(char *)s1 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(char *)s1 - *(char *)s2);
}

int	main(void)
{
	static int	bla[] = {112, 12, 122, 11, 12};
	static int	bla2[] = {112, 12, 122, 11, 11};

	printf("%d\n", ft_memcmp(bla, bla2, 10));
	printf("----------------------------\n");
	printf("%d\n", memcmp(bla, bla2, 10));
}
