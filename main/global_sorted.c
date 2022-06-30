/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:59:04 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/12 17:15:41 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	global_sorted_end(t_objc **stack_a, long *s, long max)
{
	if (found_place(stack_a, s, max, 0) > max / 2)
		while (stack_a[0]->index != 0)
			reverse_down(stack_a, s, max, "rra\n");
	else
		while (stack_a[0]->index != 0)
			reverse_up(stack_a, s, max, "ra\n");
}

void	global_sorted_push(t_objc **stack_a,
	t_objc **stack_b, long *s, long max)
{
	if (stack_a[max - 1]->location == 6)
		push_stack_a(stack_a, stack_b, s, max);
	flags_zero(stack_a, &s[0], max);
	flags_zero(stack_b, &s[1], max);
}

void	global_sorted_local(t_objc **stack_a,
	t_objc **stack_b, long *s, long max)
{
	if (stack_b[max - s[1]]->location != 6)
	{
		if (found_place_location(stack_b, s, max, 6) > max - s[1] / 2)
			reverse_down(stack_b, &s[1], max, "rrb\n");
		else
			reverse_up(stack_b, &s[1], max, "rb\n");
	}
	if (stack_a[max - 1]->location != 6)
	{
		if (found_place_location(stack_a, s, max, 6) > max - s[0] / 2)
			reverse_down(stack_a, &s[0], max, "rra\n");
		else
			reverse_up(stack_a, &s[0], max, "ra\n");
	}
}

void	global_sorted_main(t_objc **stack_a,
	t_objc **stack_b, long *s, long max)
{
	if (found_place_location(stack_a, s, max, 6) > max - s[0] / 2
		&& found_place_location(stack_b, s, max, 6) > max - s[1] / 2)
	{
		reverse_down(stack_b, &s[1], max, "");
		reverse_down(stack_a, &s[0], max, "rrr\n");
		return ;
	}
	else if (found_place_location(stack_a, s, max, 6) <= max - s[0] / 2
		&& found_place_location(stack_b, s, max, 6) <= max - s[1] / 2)
	{
		reverse_up(stack_a, &s[0], max, "");
		reverse_up(stack_b, &s[1], max, "rr\n");
		return ;
	}
	else if (found_place_location(stack_a, s, max, 6) > max - s[0] / 2
		&& found_place_location(stack_b, s, max, 6) <= max - s[1] / 2)
	{
		reverse_down(stack_a, &s[0], max, "rra\n");
		reverse_up(stack_b, &s[1], max, "rb\n");
		return ;
	}
	reverse_down(stack_b, &s[1], max, "rrb\n");
	reverse_up(stack_a, &s[0], max, "ra\n");
}

void	global_sorted(t_objc **stack_a, t_objc **stack_b, long *s, long max)
{
	global_sorted_beg(stack_a, stack_b, s, max);
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
