/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:26:16 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/06 17:40:13 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isdigit(','));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", ft_isdigit('7'));
	printf("%d\n", ft_isdigit('A'));
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", isdigit(','));
	printf("%d\n", isdigit('a'));
	printf("%d\n", isdigit('z'));
	printf("%d\n", isdigit('A'));
	printf("%d\n", isdigit('Z'));
	printf("%d\n", isdigit('7'));
}
*/