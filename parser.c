/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/28 21:18:21 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_list(long int num, t_list *stack_a)
{
	stack_a = malloc()	
}

int	ft_atoi(char *str, t_list *stack_a)
{
	int			sign;
	int			i;
	long int	num;

	sign = 1;
	i = 0;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	num = num * sign;
	if (num > 2147483647 || num < 2147483648)
		ft_error(stack_a, NULL);
	add_list(num, stack_a);
	return (i);
}

int parse_string (char *str, t_list *stack_a)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')
			str = str + ft_atoi(str, stack_a);
		else
			str++;
	}
	return (0);
}

int	parse (int argc, char **argv, t_list *stack_a)
{
	int	s;

	s = 1;
	while (s < argc)
	{
		parse_string(argv[s], stack_a);
		s++;		
	}
}
