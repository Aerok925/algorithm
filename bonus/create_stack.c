/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:08:48 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 21:42:44 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static long	*ft_atoi(char *str)
{
	long	i;
	long	nbra;
	long	minus;
	long	*ret_value;

	minus = 1;
	i = 0;
	nbra = 0;
	if ((str[i] == '-' && !str[i + 1]) || !str[i])
		return (0);
	if (str[i] == '-')
		minus *= -1 + i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nbra = nbra * 10 + (str[i] - 48);
		i++;
	}
	ret_value = malloc(sizeof(long));
	if (!ret_value)
		return (NULL);
	*ret_value = nbra * minus;
	return (ret_value);
}

static t_objc	*create_elem(char *str)
{
	t_objc	*elem;

	if (!str)
	{
		elem = malloc(sizeof(t_objc));
		if (!elem)
			return (0);
		elem->content = NULL;
		return (elem);
	}
	elem = malloc(sizeof(t_objc));
	if (!elem)
		return (0);
	elem->content = ft_atoi(str);
	if (elem->content == NULL)
	{
		free(elem);
		return (0);
	}
	return (elem);
}

void	free_arg(t_objc **stack, long argc)
{
	long	i;

	i = 0;
	if (stack)
	{
		while (i < argc)
		{
			free(stack[i]->content);
			free(stack[i]);
			i++;
		}
		free(stack);
	}
	write(2, "Error!\n", 6);
	exit (0);
}

t_objc	**create_stack(long argc, char **argv)
{
	t_objc	**stack;
	long	i;

	i = 0;
	stack = (t_objc **)malloc(sizeof(t_objc *) * (argc - 1));
	if (!stack)
		free_arg(stack, 0);
	if (argv)
	{
		while (i < argc - 1)
		{
			stack[i] = create_elem(argv[i + 1]);
			if (!stack[i])
				free_arg(stack, i);
			i++;
		}
		cheking_argument(stack, i);
	}
	else
	{
		while (i < argc - 1)
			stack[i++] = create_elem(NULL);
	}
	return (stack);
}
