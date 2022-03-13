/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_el.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 19:27:22 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_helper(t_list *stacks, int gen, int *next)
{
	pa(stacks);
	if (gen)
		stacks->stack_a->gen = gen;
	else
		down_sorted(stacks, next);
}

void	push_a_upper_mid(t_list *stacks, int gen, int *next)
{
	int	cnt;
	int	max;
	int	min;
	int	mid;
	int	last_index;

	last_index = find_last_index(stacks->stack_b);
	cnt = count_stack(stacks->stack_b);
	max = find_max(stacks->stack_b);
	min = find_min(stacks->stack_b);
	mid = ((max + min) / 2) + ((max + min) % 2);
	while (cnt > 0 && stacks->stack_b)
	{
		if (stacks->stack_b && stacks->stack_b->index == *next)
			push_a_helper(stacks, 0, next);
		else if (stacks->stack_b && stacks->stack_b->index >= mid)
			push_a_helper(stacks, gen, NULL);
		else
			rb(stacks);
		if (!stacks->stack_b)
			return ;
		cnt--;
	}
}

void	push_b(t_list *stacks, int max_order, int *next, int a_gen)
{
	int	mid;

	a_gen = stacks->stack_a->gen;
	mid = (max_order + *next) / 2 + (max_order + *next) % 2;
	while (stacks->stack_a->gen == a_gen && stacks->stack_a->gen != -1)
	{
		down_sorted(stacks, next);
		if (a_gen > 0)
		{
			while (a_gen > 0 && a_gen == stacks->stack_a->gen)
			{
				pb(stacks);
				down_sorted(stacks, next);
			}
			return ;
		}
		else if (stacks->stack_a->gen != -1)
		{
			if (stacks->stack_a->index > mid)
				ra(stacks);
			else
				pb(stacks);
		}
	}
	repair_a(stacks, *next);
}

void	push_b_first(t_list *stacks, int max_order, int *next)
{
	int	cnt;
	int	mid;

	cnt = count_stack(stacks->stack_a);
	mid = (max_order + *next) / 2 + (max_order + *next) % 2;
	while (cnt > 0)
	{
		if (stacks->stack_a->index > mid)
			ra(stacks);
		else
			pb(stacks);
		cnt--;
	}
}

void	sort_max_el(t_list *stacks, int max_order)
{
	int	next;
	int	gen;

	next = 1;
	gen = 1;
	while (stacks->stack_a->gen != -1 || stacks->stack_b)
	{
		if (gen == 1)
			push_b_first (stacks, max_order, &next);
		if (!stacks->stack_b)
			push_b(stacks, max_order, &next, 0);
		if (stacks->stack_b)
			push_a_upper_mid(stacks, gen, &next);
		sort_gen(stacks, &next);
		gen++;
	}
}
