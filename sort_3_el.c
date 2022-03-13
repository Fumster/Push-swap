/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_el.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:18:32 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 18:26:42 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sort_3(int el_1, int el_2, int el_3, t_list *stacks)
{
	if (el_1 < el_2 && el_1 < el_3)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (el_1 > el_2 && el_1 < el_3 && el_2 < el_3)
		sa(stacks);
	else if (el_1 < el_2 && el_1 > el_3 && el_2 > el_3)
		rra(stacks);
	else if (el_1 > el_2 && el_1 > el_3 && el_2 < el_3)
		ra(stacks);
	else if (el_1 > el_2 && el_1 > el_3 && el_2 > el_3)
	{
		sa(stacks);
		rra(stacks);
	}
}

void	sort_3_el(t_list *stacks)
{
	int	el_1;
	int	el_2;
	int	el_3;

	el_1 = stacks->stack_a->index;
	el_2 = stacks->stack_a->next->index;
	if (!stacks->stack_a->next->next)
	{
		if (el_1 > el_2)
			sa(stacks);
		return ;
	}
	el_3 = stacks->stack_a->next->next->index;
	if (!(el_1 < el_2 && el_2 < el_3))
		do_sort_3(el_1, el_2, el_3, stacks);
}
