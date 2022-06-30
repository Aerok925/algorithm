/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:13:11 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 23:16:14 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	brench_ft_second(t_objc ***stacks, long*s, long max, int value)
{
	if (value == 4)
		push_stack_b(stacks[0], stacks[1], s, max);
	else if (value == 5)
		reverse_up(stacks[0], &s[0], max);
	else if (value == 6)
		reverse_up(stacks[1], &s[1], max);
	else if (value == 7)
	{
		reverse_up(stacks[0], &s[0], max);
		reverse_up(stacks[1], &s[1], max);
	}
	else if (value == 8)
		reverse_down(stacks[0], &s[0], max);
	else if (value == 9)
		reverse_down(stacks[1], &s[1], max);
	else if (value == 10)
	{
		reverse_down(stacks[0], &s[0], max);
		reverse_down(stacks[1], &s[1], max);
	}
}

void	brench_ft(t_objc ***stacks, long*s, long max, int value)
{
	if (value == 0)
	{
		swap_in_stack(stacks[0], max, s[0]);
		return ;
	}
	else if (value == 1)
	{
		swap_in_stack(stacks[1], max, s[1]);
		return ;
	}
	else if (value == 2)
	{
		swap_in_stack(stacks[0], max, s[0]);
		swap_in_stack(stacks[1], max, s[1]);
	}
	else if (value == 3)
	{
		push_stack_a(stacks[0], stacks[1], s, max);
		return ;
	}
	brench_ft_second(stacks, s, max, value);
}
