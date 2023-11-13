/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:53:04 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/13 18:35:04 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (n == 0)
		return (NULL);
	if (&src[n - 1] > dest)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else if (src == dest)
		return (dest);
	else
	{
		i = 0;
		while (n > 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			n--;
			i++;
		}
	}
	return (dest);
}

int	main(void)
{
	static char arr[] = "11111111102222222222";

	printf("%s\n", arr);
	printf("%s\n", (char *)memmove(&arr[9], &arr[0], 12));
	printf("%s\n", arr);
}



a0000000b
000000000
b0000000a