/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:13:11 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/12 17:47:36 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	long	create_array(char **array)
{
	long	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static void	free_array(char **array)
{
	long	i;

	i = 0;
	while (!array[i])
	{
		free(array[i]);
		i++;
	}
}

static void	exit_error(void)
{
	write(2, "Error!\n", 7);
	exit(0);
}

static	t_objc	**create_stack_a(char **argv, long	*max, char ***array)
{
	long	i;
	t_objc	**stack_a;

	i = 0;
	while (argv[i])
		i++;
	if (i == 2)
	{
		*array = ft_split(argv[1], ' ');
		*max = create_array(*array);
		stack_a = create_stack(*max, *array);
		free_array(*array);
	}
	else
		stack_a = create_stack(*max, &argv[1]);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_objc	**stack_a;
	t_objc	**stack_b;
	long	max;
	long	s[2];
	char	**array;

	max = argc - 1;
	if (argc == 1)
		exit_error();
	array = NULL;
	stack_a = create_stack_a(argv, &max, &array);
	stack_b = create_stack(max, NULL);
	s[0] = max;
	s[1] = 0;
	if (max <= 3)
		sorted_three(stack_a, &s[0], max);
	else if (max <= 5)
		sorted_five(stack_a, stack_b, s, max);
	else
		global_sorted(stack_a, stack_b, s, max);
	free_stack(max, stack_a, stack_b);
}
