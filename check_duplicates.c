/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:35:27 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 17:36:18 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_list *stacks)
{
	t_stack	*next;
	t_stack	*stack;

	next = stacks->stack_a->next;
	stack = stacks->stack_a;
	while (stack->next)
	{
		while (next)
		{
			if (stack->num == next->num)
				ft_error(stacks);
			next = next->next;
		}
		stack = stack->next;
		next = stack->next;
	}
}
