/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:27:46 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 18:46:47 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_three(t_objc **stack, long *s, long max)
{
	if (is_sorted(stack, &s[0], max))
		return ;
	found_min(stack, max, &s[0]);
	if (stack[max - s[0]]->location == 2)
		swap_in_stack(stack, max, s[0], "a\n");
	else if (stack[max - 1]->location == 2)
		reverse_up(stack, &s[0], max, "ra\n");
	if (is_sorted(stack, &s[0], max))
		return ;
	if (stack[max - s[0]]->content[0] > stack[max - 1]->content[0])
		reverse_up(stack, &s[0], max, "ra\n");
	else
		swap_in_stack(stack, max, s[0], "a\n");
}
