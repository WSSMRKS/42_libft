/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:31:34 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/07 20:13:22 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void			*tmp;
	unsigned long	a;

	a = 0;
	tmp = dest;
	while (a < n)
	{
		*(char *) dest = *(char *) src;
		a++;
		dest++;
		src++;
	}
	return (tmp);
}

/*
#include <string.h>

int	main(void)
{
	static int	arr1[40] = {12, 39, 23, 23, 454, 6, 4, 4, 3, 2};
	static char	arr2[] = "sjdaflajsdfljas;lfkja;lkjfsflsahdkfjah";

	printf("%s\n", (char *) arr1);
	printf("%s\n", (char *) arr2);
	ft_memcpy(arr2, arr1, 40);
	printf("%s\n", (char *) arr1);
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", (char *) arr2);
	
}
*/