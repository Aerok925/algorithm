/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_location.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:59:04 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/12 17:51:57 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	define_location_found(t_objc **stack_a, long *i, long max)
{
	long	count;
	long	index;

	index = stack_a[i[0]]->index;
	count = 0;
	while (i[1] != i[0])
	{
		if (index < stack_a[i[1]]->index)
		{
			index = stack_a[i[1]]->index;
			count++;
		}
		i[1]++;
		if (i[1] == max)
			i[1] = 0;
	}
	return (count);
}

long	define_location_final(long	*array, long max)
{
	long	i[2];
	long	count;

	i[0] = 0;
	count = 0;
	while (i[0] < max)
	{
		if (array[i[0]] > array[count])
			count = i[0];
		i[0]++;
	}
	return (count);
}

void	define_local(t_objc **stack_a, long max, long *array, long *i)
{
	long	count;
	long	index;
	long	place;

	count = define_location_final(array, max);
	index = stack_a[count]->index;
	place = count;
	stack_a[place]->location = 2;
	if (place == max - 1)
		i[0] = 0;
	else
		i[0] = place + 1;
	while (i[0] != place)
	{
		if (index < stack_a[i[0]]->index)
		{
			index = stack_a[i[0]]->index;
			stack_a[i[0]]->location = 2;
		}
		i[0]++;
		if (i[0] == max)
			i[0] = 0;
	}
}

void	define_location(t_objc **stack_a, long *s, long max)
{
	long	i[2];
	long	*array;

	array = malloc(max);
	if (!array)
		return ;
	i[0] = max - s[0];
	while (i[0] < max)
	{
		if (i[0] == max - 1)
			i[1] = 0;
		else
			i[1] = i[0] + 1;
		array[i[0]] = define_location_found(stack_a, i, max);
		i[0]++;
	}
	define_local(stack_a, max, array, i);
	free(array);
}
