/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_el.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 19:30:49 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repair_a(t_list *stacks, int next)
{
	while (find_last_gen(stacks->stack_a) != -1)
	{
		if (stacks->stack_b && stacks->stack_b->index != next)
			rrr(stacks);
		else
			rra(stacks);
	}
}

void	down_sorted(t_list *stacks, int *next)
{
	while ((stacks->stack_a->index == *next
			&& find_last_gen(stacks->stack_a) == -1)
		|| (stacks->stack_a->index == 1
			&& stacks->stack_a->gen != -1))
	{
		stacks->stack_a->gen = -1;
		ra(stacks);
		*next = *next + 1;
	}
}

int	get_gen_size(t_stack *stack)
{
	int	gen;
	int	i;

	i = 0;
	gen = stack->gen;
	if (stack->gen < 1)
		return (0);
	while (gen == stack->gen)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	sort_gen(t_list *stacks, int *next)
{
	int	gen_size;

	gen_size = get_gen_size(stacks->stack_a);
	if (gen_size > 2
		&& stacks->stack_a->index > stacks->stack_a->next->index
		&& stacks->stack_a->next->index == *next)
		sa(stacks);
	down_sorted(stacks, next);
}
