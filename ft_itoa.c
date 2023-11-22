/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:17:42 by maweiss           #+#    #+#             */
/*   Updated: 2023/11/22 11:36:55 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// malloc right amount of memory, change from stdout to buff!!!

void	ft_special(int *nb, char *buff, char *digits)
{
	int		tmp;

	if (*nb == -2147483648)
	{
		write(1, "-2", 2);
		*nb = 147483648;
	}
	if (*nb < 0)
	{
		*nb = -*nb;
		write(1, "-", 1);
	}
	if (*nb == 0)
	{
		buff[0] = '0';
		buff[1] = '\0';
		return ;
	}
	tmp = *nb;
	while (tmp >= 10)
	{
		tmp /= 10;
		digits++;
	}
}

char	*ft_itoa(int nb)
{
	char	*buff;
	int		digits;
	int		i;
	
	digits = 1;
	ft_special(&nb, buff, &digits);
	i = digits - 1;
	while (nb > 0)
	{
		buff[i] = '0' + nb % 10;
		nb /= 10;
		i--;
	}
	return (buff);
}