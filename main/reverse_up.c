/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:09:26 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 21:45:05 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_up(t_objc **stack, long *s, long max, char *str)
{
	long	i;
	t_objc	*first;

	if (*s == 0)
		return ;
	i = 0;
	first = stack[max - *s];
	while (i < *s)
	{
		if (i != *s - 1)
			stack[max - *s + i] = stack[max - *s + i + 1];
		else
			stack[max - *s + i] = first;
		i++;
	}
	write(1, str, ft_strlen(str));
}

void	reverse_down(t_objc **stack, long *s, long max, char *str)
{
	long	i;
	t_objc	*first;

	if (*s == 0)
		return ;
	i = max - 1;
	first = stack[i];
	while (i > max - *s)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = first;
	write(1, str, ft_strlen(str));
}
