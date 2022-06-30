/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:16:45 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 21:44:15 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	check_arr(long *value, long a, long content)
{
	long	i;

	i = 0;
	while (i < a)
	{
		if (value[i] == content)
			return (0);
		i++;
	}
	return (1);
}

void	flag_placement(t_objc **stack_a, long *value, long max, long *s)
{
	long	i;

	i = max - s[0];
	while (i < max)
	{
		if (!check_arr(value, max / 2, stack_a[i]->content[0]))
			stack_a[i]->location = 2;
		i++;
	}
}

void	found_min(t_objc **stack_a, long max, long *s)
{
	long	i[4];
	long	*value;

	value = malloc(sizeof(long) * (s[0] / 2));
	if (!value)
		return ;
	i[0] = 0;
	i[2] = 0;
	while (i[0] < s[0] / 2)
	{
		i[3] = max - s[0];
		i[1] = 2147483647;
		while (i[3] < max)
		{
			if (stack_a[i[3]]->content[0] < i[1]
				&& check_arr(value, i[2], stack_a[i[3]]->content[0]))
				i[1] = stack_a[i[3]]->content[0];
			i[3]++;
		}
		value[i[2]++] = (long)i[1];
		i[0]++;
	}
	flag_placement(stack_a, value, max, s);
	free(value);
}
