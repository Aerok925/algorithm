/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:30:07 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 22:06:36 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	is_sorted(t_objc **stack, long *s, long max)
{
	long	i;

	i = max - *s;
	while (i < max - 1)
	{
		if (stack[i]->content[0] > stack[i + 1]->content[0])
			return (0);
		i++;
	}
	return (1);
}
