/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_nbr_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:59:04 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 18:46:54 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	nbr_command(t_objc **stack_b, long	*i, long *s)
{
	if (i[2] > s[0] / 2 && i[0] > s[1] / 2)
	{
		if (i[2] > i[1])
			stack_b[i[0]]->number = 1 + i[2];
		else
			stack_b[i[0]]->number = 1 + i[2];
	}
	else if (i[2] < s[0] / 2 && i[1] < s[1] / 2)
	{
		if (i[2] > i[1])
			stack_b[i[0]]->number = 1 + i[2];
		else
			stack_b[i[0]]->number = 1 + i[1];
	}
	else
		stack_b[i[0]]->number = 1 + i[2] + i[1];
}

void	found_nbr_command(t_objc **stack_a, t_objc **stack_b, long *s, long max)
{
	long	i[3];

	i[0] = max - s[1];
	i[1] = 1;
	while (i[0] < max)
	{
		found_max_min(stack_a, stack_b[i[0]], s, max);
		i[2] = found_place_command(stack_a, s, max);
		nbr_command(stack_b, i, s);
		i[0]++;
		i[1]++;
		flags_zero(stack_a, &s[0], max);
	}
}
