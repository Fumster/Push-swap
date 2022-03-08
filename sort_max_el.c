/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_el.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/28 21:18:21 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_gen(t_list *stacks)
{
	while(stacks->stack_a->gen == stacks->stack_a->next->gen)
			pb(stacks);
	pb(stacks);
}

int	count_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	pa_lower_mid(t_list *stacks, int mid, int flag, int *next)
{
	int cnt;

	cnt = count_stack(stacks->stack_b);
	while(cnt > 0)
	{
		if(stacks->stack_b->index > mid)
			rb(stacks);
		else
		{
			pa(stacks);
			stacks->stack_a->gen = flag;
			if(stacks->stack_a->index == *next)
				{
					ra(stacks);
					*next = *next + 1;
				}
		}
		cnt--;
	}
}

void	pb_lower_mid (t_list *stacks, int mid)
{
	int cnt;

	cnt = count_stack(stacks->stack_a);
	while(cnt > 0)
	{
		if(stacks->stack_a->index > mid)
			ra(stacks);
		else
			pb(stacks);
		cnt--;
	}
}

void	sort_max_el (t_list *stacks, int max)
{
	int	i = 0;
	int	next;
	int	mid;
	int	flag;

	next = 1;
	flag = 1;
	mid = max / 2;
	while (i < 9)
	{
	if(stacks->stack_a->gen == 0)
		pb_lower_mid(stacks, mid);
	else
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
//
}
