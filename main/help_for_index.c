/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:59:04 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 21:44:33 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	found_in_array(long nbr, long size, long *array)
{
	long	i;

	i = 0;
	while (i < size)
	{
		if (nbr == array[i])
			return (1);
		i++;
	}
	return (0);
}

void	ctrl_v_index(t_objc **stack, long *array, long *s, long max)
{
	long	i;
	long	a;

	a = 0;
	while (a < max)
	{
		i = max - s[0];
		while (i < max)
		{
			if (stack[i]->content[0] == array[a])
				stack[i]->index = max - a - 1;
			i++;
		}
		a++;
	}
}

void	found_index(t_objc **stack, long *s, long max)
{
	long	i;
	long	max_value;
	long	*array;
	long	a;

	array = malloc(sizeof(long) * max - 1);
	if (!array)
		exit (0);
	a = 0;
	while (a < max)
	{
		max_value = -2147483648;
		i = max - s[0];
		while (i < max)
		{
			if (max_value < stack[i]->content[0]
				&& !found_in_array(stack[i]->content[0], a, array))
				max_value = stack[i]->content[0];
			i++;
		}
		array[a++] = max_value;
	}
	ctrl_v_index(stack, array, s, max);
	free(array);
}

long	found_place_location(t_objc **stack, long *s, long max, long location)
{
	long	i;

	i = max - s[0];
	while (i < max)
	{
		if (stack[i]->location == location)
			return (i);
		i++;
	}
	return (0);
}

long	found_place(t_objc **stack, long *s, long max, long index)
{
	long	i;

	i = max - s[0];
	while (i < max)
	{
		if (stack[i]->index == index)
			return (i);
		i++;
	}
	return (0);
}
