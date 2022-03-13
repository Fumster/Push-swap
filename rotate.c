/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:14:10 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 18:15:31 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = *stack;
	while (last && last->next)
		last = last->next;
	if (first && first->next)
	{
		*stack = first->next;
		last->next = first;
		first->next = NULL;
		return (0);
	}
	return (1);
}

void	ra(t_list *stacks)
{
	int	err;

	err = rotate_stack (&stacks->stack_a);
	if (!err)
		write(1, "ra\n", 3);
}

void	rb(t_list *stacks)
{
	int	err;

	err = rotate_stack (&stacks->stack_b);
	if (!err)
		write(1, "rb\n", 3);
}

void	rr(t_list *stacks)
{
	int	err;

	err = rotate_stack (&stacks->stack_a);
	err += rotate_stack (&stacks->stack_b);
	if (!err)
		write(1, "rr\n", 3);
}
