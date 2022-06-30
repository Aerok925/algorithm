/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:32:18 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 22:54:16 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_stack_b(t_objc **stack_a, t_objc **stack_b,
	long *s, long max)
{
	if (s[0] == 0)
		return ;
	stack_b[max - s[1] - 1]->content = stack_a[max - s[0]]->content;
	stack_a[max - s[0]]->content = NULL;
	s[0] -= 1;
	s[1] += 1;
}

void	push_stack_a(t_objc **stack_a, t_objc **stack_b,
	long *s, long max)
{
	if (s[1] == 0)
		return ;
	stack_a[max - s[0] - 1]->content = stack_b[max - s[1]]->content;
	stack_b[max - s[1]]->content = NULL;
	s[1] -= 1;
	s[0] += 1;
}
