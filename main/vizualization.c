/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:24:36 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/12 17:16:29 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vizualization(long max, t_objc **stack_a, t_objc **stack_b)
{
	long	i;

	i = 0;
	while (i < max)
	{
		if (stack_a[i]->content)
			printf("%3ld) %10ld %10ld %10ld", i,
				stack_a[i]->content[0],
				stack_a[i]->location, stack_a[i]->index);
		else if (!stack_a[i]->content)
			printf("                 ");
		if (stack_b[i]->content)
			printf("    %10ld %10ld %10ld %10ld",
				stack_b[i]->content[0], stack_b[i]->location,
				stack_b[i]->index, stack_b[i]->number);
		else if (!stack_b[i]->content)
			printf("                 ");
		printf("\n");
		i++;
	}
	if (!stack_b[0])
		printf("asd");
	printf("%33c    %40c\n", 'a', 'b');
}
