/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:06:17 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 21:46:25 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_objc
{
	long	location;
	long	*content;
	long	index;
	long	number;
}	t_objc;

t_objc	**create_stack(long argc, char **argv);
long	ft_strlen(char *str);
void	vizualization(long argc, t_objc **stack_a, t_objc **stack_b);
void	free_stack(long argc, t_objc **stack_a, t_objc **stack_b);
void	cheking_argument(t_objc **stack, long max);
void	free_arg(t_objc **stack, long argc);
void	swap_in_stack(t_objc **stack, long max, long count, char *str);
void	push_stack_b(t_objc **stack_a, t_objc **stack_b, long *s, long max);
void	push_stack_a(t_objc **stack_a, t_objc **stack_b, long *s, long max);
void	reverse_up(t_objc **stack, long *s, long max, char *str);
void	reverse_down(t_objc **stack, long *s, long max, char *str);
void	sorted_six(t_objc **stack_a, t_objc **stack_b, long max, long *s);
long	check_arr(long *value, long a, long content);
void	flag_placement(t_objc **stack_a, long *value, long max, long *s);
void	found_min(t_objc **stack_a, long max, long *s);
long	is_sorted(t_objc **stack, long *s, long max);
void	sorted_three(t_objc **stack, long *s, long max);
void	sorted_many(t_objc **stack_a, t_objc **stack_b, long *s, long max);
void	flags_zero(t_objc **stack, long *s, long max);
void	global_sorted(t_objc **stack_a, t_objc **stack_b, long *s, long max);
void	found_index(t_objc **stack, long *s, long max);
long	found_place(t_objc **stack, long *s, long max, long index);
long	found_in_array(long nbr, long size, long *array);
void	ctrl_v_index(t_objc **stack, long *array, long *s, long max);
void	define_location(t_objc **stack_a, long *s, long max);
long	found_place_location(t_objc **stack, long *s, long max, long location);
long	check_valid_stack(t_objc **stack, long *s, long max);
long	has_min(t_objc **stack_a, t_objc *stack_b, long *s, long max);
long	found_min_number(t_objc **stack_b, long *s, long max);
long	found_place_command(t_objc **stack_a, long	*s, long max);
void	found_max_min(t_objc **stack_a, t_objc *stack_b, long *s, long max);
void	found_nbr_command(t_objc**stack_a, t_objc**stack_b, long*s, long max);
void	global_sorted_beg(t_objc**stack_a, t_objc**stack_b, long*s, long max);
void	sorted_five(t_objc **stack_a, t_objc **stack_b, long *s, long max);
void	global_sorted_main(t_objc**stack_a, t_objc**stack_b, long*s, long max);
void	global_sorted_local(t_objc**stack_a, t_objc**stack_b, long*s, long max);
void	global_sorted_push(t_objc**stack_a, t_objc**stack_b, long*s, long max);
void	global_sorted_end(t_objc **stack_a, long *s, long max);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char	*dst, char	*src, size_t	size);

#endif //PUSH_SWAP_H
