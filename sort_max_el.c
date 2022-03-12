/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_el.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/12 12:22:35 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_stack *stack, int max)
{
	int	pos;

	pos = 1;
	while (stack->index != max)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

void	push_a_sorted(t_list *stacks, int *cnt, int *next, int gen)
{
	int	middle;
	int	max;
	int	max_pos;

	middle = (*cnt / 2) + (*cnt % 2);
	
	if (stacks->stack_b->index < stacks->stack_b->next->index)
		sb(stacks);
	pa(stacks);
	ra(stacks);
	pa(stacks);
	ra(stacks);
	*cnt = 0;
	while (*cnt < 0)
	{
		max = find_max(stacks->stack_b);
		max_pos = find_max_pos(stacks->stack_b, max);
		if (max_pos <= middle && stacks->stack_b->index != max)
			rb(stacks);
		else if (stacks->stack_b->index != max)
			rrb(stacks);
		pa(stacks);
		stacks->stack_a->gen = gen;
		if (stacks->stack_a->index == *next)
		{
			ra(stacks);
			*next = *next + 1;
		}
		*cnt = *cnt - 1;
	}
}

void	push_a_upper_mid(t_list *stacks, int gen, int *next)
{
	int cnt;
	int max;
	int min;
	int mid;

	cnt = count_stack(stacks->stack_b);
	max = find_max(stacks->stack_b);
	min = find_min(stacks->stack_b);
	mid = (max + min) / 2;
	while(cnt > 0)
	{
		if(stacks->stack_b->index == *next)
			{
				stacks->stack_b->gen = -1;
				pa(stacks);
				ra(stacks);
				*next = *next + 1;
			}
	//	else if (cnt == 2)
	//		push_a_sorted(stacks, &cnt, next, gen);
		else if(stacks->stack_b->index >= mid)
		{
			pa(stacks);
			stacks->stack_a->gen = gen;
		}
		else
			rb(stacks);
		cnt--;
	}
}

void	push_b (t_list *stacks, int max_order, int next)
{
	int cnt;
	int a_gen;
	int	min;
	int	mid;

	min = find_min(stacks->stack_a);
	cnt = count_stack(stacks->stack_a);
	a_gen = stacks->stack_a->gen;
	if(a_gen != 0)
	{
		while(a_gen == stacks->stack_a->gen)
		   pb(stacks);
		return;	
	}
	mid = (max_order + next) / 2 + (max_order + next) % 2;
	while(cnt > 0 && stacks->stack_a->gen == 0)
	{
		if(stacks->stack_a->index > mid)
			ra(stacks);
		else
			pb(stacks);
		cnt--;
	}
}

void	repair_a(t_list *stacks, int next)
{
	t_stack	*tmp_a;

	tmp_a = stacks->stack_a;
	while(1)
	{
		while(tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_a->index == (next - 1))
			return;
		rra(stacks);
		tmp_a = stacks->stack_a;
	}
}

void	sort_max_el (t_list *stacks, int max_order)
{
	int	next;
	int	gen;
	int	b_cntr;
//	int i = 20;

	next = 1;
	gen = 1;
	
	//while(!is_sorted(stacks) || count_stack(stacks->stack_b))
	while(stacks->stack_a->gen != -1 || stacks->stack_b)
	{
		b_cntr = count_stack(stacks->stack_b);
		if (gen > 1)
			repair_a(stacks, next);
		if (!b_cntr)
			push_b(stacks, max_order, next);
		else
		{
			push_a_upper_mid(stacks, gen, &next);
			gen++;
		}
	}
		
		
/*	else
		pb_gen(stacks);
	max = count_stack(stacks->stack_b);
	mid = max / 2;
	printf("mid-%d\n", mid);
	pa_lower_mid(stacks, mid, flag, &next);
	while(stacks->stack_b)
	{
		mid = ((max - mid) / 2) + mid + next;
		printf("mid-%d\n", mid);
		pa_lower_mid(stacks, mid, flag, &next);
	}
	flag++;
	i++;
	}
//
//*/
}
