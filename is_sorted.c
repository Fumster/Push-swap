/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:04:17 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 18:05:06 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_sorted(t_list *stacks)
{
	t_stack	*stack;

	stack = stacks->stack_a;
	while (stack->next)
	{
		if (stack->index < stack->next->index)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
