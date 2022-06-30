/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:28:51 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 18:46:54 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(long max, t_objc **stack_a, t_objc **stack_b)
{
	long	i;

	i = 0;
	max = 0;
	while (i < max)
	{
		free(stack_a[i]->content);
		free(stack_a[i]);
		free(stack_b[i]);
		i++;
	}
	if (!stack_a && !stack_b)
	{
		free(stack_a);
		free(stack_b);
	}
}
