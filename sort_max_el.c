/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_el.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/10 21:43:29 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if(stacks->stack_b->index >= mid)
		{
			pa(stacks);
			stacks->stack_a->gen = gen;
		}
		else
		{
			if(stacks->stack_b->index == *next)
				{
					pa(stacks);
					ra(stacks);
					*next = *next + 1;
				}
			rb(stacks);
		}
		cnt--;
	}
}

void	push_b (t_list *stacks, int max_order)
{
	int cnt;
	int gen;
	int	min;
	int	mid;

	min = find_min(stacks->stack_a);
	cnt = count_stack(stacks->stack_a);
	gen = stacks->stack_a->gen;
	if(gen != 0)
	{
		while(gen == stacks->stack_a->gen)
		   pb(stacks);
		return;	
	}
	mid = (max_order + min) / 2 + (max_order + min) % 2;
	while(cnt > 0)
	{
		if(stacks->stack_a->index > mid)
			ra(stacks);
		else
			pb(stacks);
		cnt--;
	}
}

void	sort_max_el (t_list *stacks, int max_order)
{
	int	next;
	int	gen;
	int	b_cntr;
	int	i;

	next = 1;
	gen = 1;
	i = 15;
	
	while(i > 0)
	{
		b_cntr = count_stack(stacks->stack_b);
		if (!b_cntr)
			push_b(stacks, max_order);
		else
		{
			push_a_upper_mid(stacks, gen, &next);
			gen++;
		}
		i--;
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
