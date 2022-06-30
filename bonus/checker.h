/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:38:12 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 22:58:42 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_objc
{
	long	*content;
}	t_objc;

t_objc	**create_stack(long argc, char **argv);
void	free_arg(t_objc **stack, long argc);
void	cheking_argument(t_objc **stack, long max);
void	error(char *str);
void	clear_str(char *str);
int		str_cmp(char *str, char *str_main);
int		found_str(char *str, char **str_main);
int		filing_str(char *str);
void	brench_ft(t_objc ***stacks, long*s, long max, int value);
void	swap_in_stack(t_objc **stack, long max, long count);
long	is_sorted(t_objc **stack, long *s, long max);
void	push_stack_b(t_objc **stack_a, t_objc **stack_b, long *s, long max);
void	push_stack_a(t_objc **stack_a, t_objc **stack_b, long *s, long max);
void	reverse_up(t_objc **stack, long *s, long max);
void	reverse_down(t_objc **stack, long *s, long max);

#endif //CHECKER_H
