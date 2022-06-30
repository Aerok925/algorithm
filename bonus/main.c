/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:13:11 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 23:13:38 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stacks(t_objc **stack_a, t_objc **stack_b, long max)
{
	long	i;

	i = 0;
	while (i < max)
	{
		free(stack_a[i]->content);
		free(stack_a[i]);
		free(stack_b[i]->content);
		free(stack_b[i]);
		i++;
	}
	free(stack_b);
	free(stack_a);
}

static int	standart_input(int *read_value, char *c, char *str)
{
	int	i;

	i = 0;
	while (*c != '\n')
	{
		*read_value = read(0, c, 1);
		if (*read_value == 0)
		{
			free(str);
			return (0);
		}
		str[i++] = *c;
	}
	return (1);
}

void	processor_str(t_objc ***stacks, long *s, long max)
{
	char	*str;
	int		read_value;
	char	c;
	int		value;

	read_value = 1;
	str = malloc(10000);
	if (!str)
		exit (0);
	while (read_value != 0)
	{
		if (standart_input(&read_value, &c, str) == 0)
			return ;
		value = filing_str(str);
		if (value == -1)
			error(str);
		brench_ft(stacks, s, max, value);
		c = ' ';
		clear_str(str);
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_objc	**stack_a;
	t_objc	**stack_b;
	t_objc	**stacks[2];
	long	max;
	long	s[2];

	max = argc - 1;
	s[0] = max;
	s[1] = 0;
	if (argc == 1)
		return (0);
	stack_a = create_stack(argc, argv);
	stack_b = create_stack(argc, NULL);
	if (!stack_a && !stack_b)
		return (0);
	stacks[0] = stack_a;
	stacks[1] = stack_b;
	processor_str(stacks, s, max);
	if (is_sorted(stack_a, s, max) && s[1] == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(stack_a, stack_b, max);
}
