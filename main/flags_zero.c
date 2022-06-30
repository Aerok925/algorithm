/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:29:32 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 18:46:51 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	max_in_stack_a(t_objc **stack_a, t_objc **stack_b, long max, long *s)
{
	long	i;

	i = max - s[0];
	if (s[1] == 0)
		return (0);
	while (i < max)
	{
		if (stack_a[i]->content[0] > stack_b[max - s[1]]->content[0])
			return (1);
		i++;
	}
	return (0);
}

void	flags_zero(t_objc **stack, long *s, long max)
{
	long	i;

	i = max - *s;
	while (i < max)
	{
		stack[i]->location = 1;
		i++;
	}
}
