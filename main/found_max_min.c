/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_max_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:59:04 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/12 17:30:25 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	found(t_objc **stack_a, long *s, long max)
{
	long	index;
	long	i;
	long	a;

	a = 0;
	i = max - s[0];
	index = i;
	while (i < max)
	{
		if (stack_a[i]->index < stack_a[index]->index)
			index = i;
		i++;
	}
	if (index == max - s[0])
		stack_a[max - 1]->location = 6;
	else
		stack_a[index - 1]->location = 6;
}

static	void	found_max_min_dopolnation(t_objc **stack_a,
	t_objc *stack_b, long *array, long *i)
{
	while (i[0] < i[2])
	{
		if (stack_b->content[0] > stack_a[i[0]]->content[0])
		{
			array[i[1]] = stack_a[i[0]]->content[0];
			i[1] += 1;
		}
		i[0] += 1;
	}
}

static void	found_please(long	*i, long *array)
{
	i[0] = array[i[1]];
	while (i[1] >= 0)
	{
		if (array[i[1]] > i[0])
			i[0] = array[i[1]];
		i[1] -= 1;
	}
}

static void	found_plus_plus(t_objc **stack_a, long max, long *i)
{
	while (i[1] < max)
	{
		if (stack_a[i[1]]->content[0] == i[0])
		{
			stack_a[i[1]]->location = 6;
			break ;
		}
		i[1] += 1;
	}
}

void	found_max_min(t_objc **stack_a, t_objc *stack_b, long *s, long max)
{
	long	i[3];
	long	*array;

	i[1] = 0;
	i[2] = max;
	i[0] = max - s[0];
	if (!has_min(stack_a, stack_b, s, max))
	{
		found(stack_a, s, max);
		return ;
	}
	array = malloc(sizeof(long) * max);
	if (array == NULL)
		return ;
	i[1] = 0;
	i[0] = max - s[0];
	found_max_min_dopolnation(stack_a, stack_b, array, i);
	i[1] -= 1;
	found_please(i, array);
	i[1] = max - s[0];
	found_plus_plus(stack_a, max, i);
	free(array);
}
