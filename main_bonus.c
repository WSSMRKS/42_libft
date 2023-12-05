/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:14:07 by maweiss           #+#    #+#             */
/*   Updated: 2023/12/05 21:46:09 by maweiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	t_list	*test;
	t_list	*test2;
	t_list	*test3;
	char	c;
	int		a;
	int		b;

	test = malloc(sizeof(t_list));
	test2 = malloc(sizeof(t_list));
	test3 = malloc(sizeof(t_list));
	c = 'T';
	a = 132654;
	b = -255;

	test->content = &c;
	test->next = test2;
	test2->content = &a;
	test2->next = test3;
	test3->content = &b;
	test3->next = NULL;

	printf("%d\n", ft_lstsize(test));
}
