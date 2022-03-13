/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_el.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 16:00:53 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	down_sorted(t_list *stacks, int *next)
{
		while ((stacks->stack_a->index == *next && 
				find_last_gen(stacks->stack_a) == -1) ||
				(stacks->stack_a->index == 1 &&
				 stacks->stack_a->gen != -1))
		{
			stacks->stack_a->gen = -1;
			ra(stacks);
			*next = *next + 1;
		}
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
		//printf("push_a_func\n");
		if(stacks->stack_b && stacks->stack_b->index == *next)
		{
			pa(stacks);
			down_sorted(stacks, next);
		}
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
		//printf("end_push_a_func\n");
	}
}

void	push_b (t_list *stacks, int max_order, int *next, int a_gen, int mid)
{
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
			return;
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

void	push_b_first (t_list *stacks, int max_order, int *next)
{
	int cnt;
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

int	get_gen_size(t_stack *stack)
{
	int	gen;
	int i;
	
	i = 0;
	gen = stack->gen;
	if (stack->gen < 1)
		return(0);
	while (gen == stack->gen)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	sort_gen (t_list *stacks, int *next)
{
	int	gen_size;

	gen_size = get_gen_size(stacks->stack_a);
	if (gen_size > 2 && 
			stacks->stack_a->index > stacks->stack_a->next->index &&
			stacks->stack_a->next->index == *next)
		sa(stacks);
	down_sorted(stacks, next);
}

void	sort_max_el (t_list *stacks, int max_order)
{
	int	next;
	int	gen;
//	int i = 40;

	next = 1;
	gen = 1;
	
//	while (i-- > 0)
	while(stacks->stack_a->gen != -1 || stacks->stack_b)
	{
		if (gen == 1)	
			push_b_first (stacks, max_order, &next);
		if (!stacks->stack_b)
			push_b(stacks, max_order, &next, 0, 0);
		if (stacks->stack_b)
			push_a_upper_mid(stacks, gen, &next);
		sort_gen(stacks, &next);
		gen++;
	}
}
