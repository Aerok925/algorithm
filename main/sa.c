/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:21:51 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 18:47:01 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_in_stack(t_objc **stack, long max, long count, char *str)
{
	t_objc	*swap;

	if (count < 2)
		return ;
	swap = stack[max - count];
	stack[max - count] = stack[max - count + 1];
	stack[max - count + 1] = swap;
	write(1, "s", 1);
	write(1, str, 2);
}
