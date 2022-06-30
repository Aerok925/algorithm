/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:21:51 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 21:56:21 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_in_stack(t_objc **stack, long max, long count)
{
	t_objc	*swap;

	if (count < 2)
		return ;
	swap = stack[max - count];
	stack[max - count] = stack[max - count + 1];
	stack[max - count + 1] = swap;
}
