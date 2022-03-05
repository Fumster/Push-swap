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

void	add_list(int num, t_list *stacks)
{
	t_stack	*new;
	t_stack	*last;

	new = (t_stack*)malloc(sizeof(t_stack));
	last = stacks->stack_a;
	if (!new)
		ft_error(stacks);
	new->num = num;
	new->index = 0;
	new->gen = 0;
	new->sorted = 0;
	new->next = NULL;
	if (!stacks->stack_a)
	{
		stacks->stack_a = new;
		return;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

void	ft_atoi(char *str, t_list *stacks, int *i)
{
	int			sign;
	long int	num;

	sign = 1;
	num = 0;
	if (str[*i] == '-')
	{
		sign = -1;
		*i = *i + 1;
	}
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		num = num * 10 + (str[*i] - 48);
		*i = *i + 1;
	}
	num = num * sign;
	if (num > 2147483647 || num < -2147483648)
		ft_error(stacks);
	add_list(num, stacks);
}

void	parse_string (char *str, t_list *stacks)
{
	int	offset;
	
	offset = 0;
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')
		{
			offset = 0;
			ft_atoi(str, stacks, &offset);
			str = str + offset;
		}
		else
			str++;
	}
}

void	parse (int argc, char **argv, t_list *stacks)
{
	int	s;

	s = 1;
	while (s < argc)
	{
		parse_string(argv[s], stacks);
		s++;		
	}
}
