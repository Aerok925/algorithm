/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnappa <jnappa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:13:11 by jnappa            #+#    #+#             */
/*   Updated: 2021/11/11 22:00:40 by jnappa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(char *str)
{
	free(str);
	write(2, "Error\n", 6);
	exit(0);
}

void	clear_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		str[i++] = '\0';
}

int	str_cmp(char *str, char *str_main)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != str_main[i])
			return (0);
		i++;
	}
	return (1);
}

int	found_str(char *str, char **str_main)
{
	int	i;

	i = 0;
	while (str_main[i])
	{
		if (str_cmp(str, str_main[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	filing_str(char *str)
{
	char	*str_main[12];

	str_main[0] = "sa\n";
	str_main[1] = "sb\n";
	str_main[2] = "ss\n";
	str_main[3] = "pa\n";
	str_main[4] = "pb\n";
	str_main[5] = "ra\n";
	str_main[6] = "rb\n";
	str_main[7] = "rr\n";
	str_main[8] = "rra\n";
	str_main[9] = "rrb\n";
	str_main[10] = "rrr\n";
	str_main[11] = NULL;
	return (found_str(str, str_main));
}
