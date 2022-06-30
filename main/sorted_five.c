/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:27:46 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/12 17:36:10 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorted_five_location(t_objc **stack_a,
	t_objc **stack_b, long *s, long max)
{
	while (s[1] != 0)
	{
		found_nbr_command(stack_a, stack_b, s, max);
		found_max_min(stack_a, stack_b[found_min_number(stack_b, s, max)],
			s, max);
		while (stack_a[max - 1]->location != 6
			|| stack_b[max - s[1]]->location != 6)
		{
			if (stack_a[max - 1]->location != 6
				&& stack_b[max - s[1]]->location != 6)
			{
				global_sorted_main(stack_a, stack_b, s, max);
				continue ;
			}
			global_sorted_local(stack_a, stack_b, s, max);
		}
		global_sorted_push(stack_a, stack_b, s, max);
	}
	global_sorted_end(stack_a, s, max);
}

void	sorted_five(t_objc **stack_a, t_objc **stack_b, long *s, long max)
{
	if (is_sorted(stack_a, &s[0], max))
		return ;
	found_index(stack_a, s, max);
	if (max == 5)
		push_stack_b(stack_a, stack_b, s, max);
	push_stack_b(stack_a, stack_b, s, max);
	while (1)
	{
		if (is_sorted(stack_a, &s[0], max))
			break ;
		found_min(stack_a, max, &s[0]);
		if (stack_a[max - s[0]]->location == 2)
			swap_in_stack(stack_a, max, s[0], "a\n");
		else if (stack_a[max - 1]->location == 2)
			reverse_up(stack_a, &s[0], max, "ra\n");
		if (is_sorted(stack_a, &s[0], max))
			break ;
		if (stack_a[max - s[0]]->content[0] > stack_a[max - 1]->content[0])
			reverse_up(stack_a, &s[0], max, "ra\n");
		else
			swap_in_stack(stack_a, max, s[0], "a\n");
	}
	sorted_five_location(stack_a, stack_b, s, max);
}
