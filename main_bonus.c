/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maweiss <maweiss@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:14:07 by maweiss           #+#    #+#             */
/*   Updated: 2023/12/06 12:57:28 by maweiss          ###   ########.fr       */
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

	test = malloc(sizeof(t_list));
	test2 = malloc(sizeof(t_list));
	test3 = malloc(sizeof(t_list));
	c = 'T';
	a = 132654;
	test->content = &c;
	test->next = test2;
	test2->content = &a;
	test2->next = test3;
	test3->content = &c;
	test3->next = NULL;
	printf("ft_lstsize------------------------------------------\n");
	printf("ft_lstsize test 1:\n");
	if (ft_lstsize(test) == 3)
		printf("ft_lstsize return value: 3 --> Correct\n");
	else
		printf("ft_lstsize return value != 3 --> Fail!\n");
	printf("ft_lstlast------------------------------------------\n");
	printf("ft_lstlast test 1: \n");
	if (ft_lstlast(test) == test3)
		printf("ft_lstsize return value == test3 --> Correct\n");
	if (ft_lstlast(test) != test3)
		printf("ft_lstsize return value != test3 --> Fail\n");
}
