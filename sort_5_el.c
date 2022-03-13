/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_el.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:26:52 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 18:41:55 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b_5(t_list *stacks, int pos)
{
	if (pos == 4)
	{
		rra(stacks);
		rra(stacks);
	}
	else if (pos == 5)
		rra(stacks);
}

void	move_to_b(t_list *stacks, int pos, int cntr)
{
	if (pos == 2)
		ra(stacks);
	else if (pos == 3)
	{
		ra(stacks);
		ra(stacks);
	}
	else if (pos > 3)
	{
		if (cntr == 5)
			move_to_b_5(stacks, pos);
		else
			rra(stacks);
	}
	pb(stacks);
}

int	find_pos(t_list *stacks, int num)
{
	int		pos;
	t_stack	*st_a;

	pos = 1;
	st_a = stacks->stack_a;
	while (st_a->index != num)
	{
		st_a = st_a->next;
		pos++;
	}
	return (pos);
}

void	sort_5_el(t_list *stacks, int cntr)
{
	int	pos;

	pos = find_pos(stacks, 1);
	move_to_b(stacks, pos, cntr);
	pos = find_pos(stacks, 2);
	if (cntr > 4)
		move_to_b(stacks, pos, cntr - 1);
	sort_3_el(stacks);
	pa(stacks);
	pa(stacks);
}
