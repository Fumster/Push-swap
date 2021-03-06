/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:09:10 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 18:10:08 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	tmp = *src;
	if (*src)
	{
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
		return (0);
	}
	return (1);
}

void	pa(t_list *stacks)
{
	int	err;

	err = push (&stacks->stack_a, &stacks->stack_b);
	if (!err)
		write(1, "pa\n", 3);
}

void	pb(t_list *stacks)
{
	int	err;

	err = push (&stacks->stack_b, &stacks->stack_a);
	if (!err)
		write(1, "pb\n", 3);
}
