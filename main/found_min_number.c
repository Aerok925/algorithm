/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_min_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:59:04 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 18:46:54 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	check_valid_stack(t_objc **stack, long *s, long max)
{
	long	i;

	i = max - s[0];
	while (i < max)
	{
		if (stack[i]->location == 1)
			return (0);
		i++;
	}
	return (1);
}

long	has_min(t_objc **stack_a, t_objc *stack_b, long *s, long max)
{
	long	i;

	i = max - s[0];
	while (i < max)
	{
		if (stack_a[i]->content[0] < stack_b->content[0])
			return (1);
		i++;
	}
	return (0);
}

long	found_place_command(t_objc **stack_a, long	*s, long max)
{
	long	i;
	long	a;

	a = 1;
	i = max - s[0];
	while (i < max)
	{
		if (stack_a[i]->location == 6)
			return (a);
		i++;
		a++;
	}
	return (0);
}

long	found_min_number(t_objc **stack_b, long *s, long max)
{
	long	nbr;
	long	i;

	i = max - s[1];
	nbr = stack_b[i]->number;
	while (i < max)
	{
		if (stack_b[i]->number < nbr)
			nbr = stack_b[i]->number;
		i++;
	}
	i = max - s[1];
	while (i < max)
	{
		if (nbr == stack_b[i]->number)
		{
			stack_b[i]->location = 6;
			return (i);
		}
		i++;
	}
	return (0);
}
