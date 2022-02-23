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

t_list	*add_list(int num, t_list *stack)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(t_list));
	last = stack;
	if (!new)
		ft_error(stack, NULL);
	new->num = num;
	new->index = 0;
	new->gen = 0;
	new->sorted = 0;
	new->next = NULL;
	if (!stack)
	{
		stack = new;
		return (stack);
	}
	while (last->next)
		last = last->next;
	last->next = new;
	return (stack);
}

t_list	*ft_atoi(char *str, t_list *stack, int *i)
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
		ft_error(stack, NULL);
	stack = add_list(num, stack);
	return (stack);
}

t_list	*parse_string (char *str, t_list *stack)
{
	int	offset;
	
	offset = 0;
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')
		{
			offset = 0;
			stack = ft_atoi(str, stack, &offset);
			str = str + offset;
		}
		else
			str++;
	}
	return (stack);
}

t_list	*parse (int argc, char **argv)
{
	int	s;
	t_list *stack;

	s = 1;
	stack = NULL;
	while (s < argc)
	{
		stack = parse_string(argv[s], stack);
		s++;		
	}
	return (stack);
}
