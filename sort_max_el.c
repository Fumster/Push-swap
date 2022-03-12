/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_el.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 00:25:16 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_last_index(t_stack *stack)
{
	int	ind;
	
	if (!stack)
		return (0);
	while(stack->next)
		stack = stack->next;
	ind = stack->index;
	return (ind);
}

void	push_a_upper_mid(t_list *stacks, int gen, int *next)
{
	int cnt;
	int max;
	int min;
	int mid;
	int	last_index;

	last_index = find_last_index(stacks->stack_b);
	cnt = count_stack(stacks->stack_b);
	max = find_max(stacks->stack_b);
	min = find_min(stacks->stack_b);
	mid = ((max + min) / 2) + ((max + min) % 2);
	while(cnt > 0 && stacks->stack_b)
	{
		while (stacks->stack_a->index == *next)
		{
			stacks->stack_a->gen = -1;
			ra(stacks);
			*next = *next + 1;
		}
		if(stacks->stack_b && stacks->stack_b->index == *next)
			pa(stacks);
		else if(stacks->stack_b && stacks->stack_b->index >= mid)
		{
			pa(stacks);
			stacks->stack_a->gen = gen;
		}
		else
			rb(stacks);
		if (!stacks->stack_b)
			return;
		cnt--;
	}
}

int	find_last_gen(t_stack *stack)
{
	int	gen;
	
	while(stack->next)
		stack = stack->next;
	gen = stack->gen;
	return (gen);
}

void	push_b (t_list *stacks, int max_order, int *next)
{
	int a_gen;
	int	mid;

	a_gen = stacks->stack_a->gen;
	mid = (max_order + *next) / 2 + (max_order + *next) % 2;
	while (stacks->stack_a->gen == a_gen && stacks->stack_a->gen != -1)
	{
		if (stacks->stack_a->index == *next)
		{
			stacks->stack_a->gen = -1;
			ra(stacks);
			*next = *next + 1;
		}
		else if (a_gen == stacks->stack_a->gen)
			pb(stacks);
		else
		{
			if (stacks->stack_a->index > mid)
				ra(stacks);
			else
				pb(stacks);
		}
	}
}

void	push_b_first (t_list *stacks, int max_order, int next)
{
	int cnt;
	int	mid;

	cnt = count_stack(stacks->stack_a);
	mid = (max_order + next) / 2 + (max_order + next) % 2;
	while (cnt > 0)
	{
		if (stacks->stack_a->index > mid)
			ra(stacks);
		else
			pb(stacks);
		cnt--;
	}
}

void	repair_a(t_list *stacks, int next)
{
	while(find_last_gen(stacks->stack_a) != -1)
	{
		if(stacks->stack_b && stacks->stack_b->index != next)
			rrr(stacks);
		else
			rra(stacks);
	}
}

void	sort_max_el (t_list *stacks, int max_order)
{
	int	next;
	int	gen;

	next = 1;
	gen = 1;
	
	while(stacks->stack_a->gen != -1 || stacks->stack_b)
	{
		if (gen == 1)	
			push_b_first (stacks, max_order, next);
		else if (next > 1)
			repair_a(stacks, next);
		if (!stacks->stack_b)
			push_b(stacks, max_order, &next);
		else if (stacks->stack_b)
			push_a_upper_mid(stacks, gen, &next);
		gen++;
	}
}
