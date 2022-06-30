/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:19:35 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/12 17:51:47 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	cheking_argument(t_objc **stack, long max)
{
	long	i;
	long	a;

	i = 0;
	while (i < max)
	{
		a = 0;
		if (stack[i]->content[0] > 2147483647
			|| stack[i]->content[0] < -2147483648)
			free_arg(stack, max);
		while (a < i)
		{
			if (stack[i]->content[0] == stack[a]->content[0])
				free_arg(stack, max);
			a++;
		}
		i++;
	}
}
