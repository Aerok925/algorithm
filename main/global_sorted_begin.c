/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sorted_begin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:59:04 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 18:46:56 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	global_sorted_beg(t_objc **stack_a,
	t_objc **stack_b, long *s, long max)
{
	long	i;

	i = max - s[0];
	found_index(stack_a, s, max);
	define_location(stack_a, s, max);
	while (!check_valid_stack(stack_a, s, max))
	{
		if (stack_a[max - s[0]]->location != 1)
			reverse_up(stack_a, &s[0], max, "ra\n");
		if (check_valid_stack(stack_a, s, max))
			break ;
		if (stack_a[max - s[0]]->location == 1)
			push_stack_b(stack_a, stack_b, s, max);
	}
}
