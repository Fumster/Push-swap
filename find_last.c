/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:34:46 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 17:58:03 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	find_last_index(t_stack *stack)
{
	stack = find_last_stack(stack);
	if (stack)
		return (stack->index);
	else
		return (0);
}

int	find_last_gen(t_stack *stack)
{
	stack = find_last_stack(stack);
	if (stack)
		return (stack->gen);
	else
		return (0);
}
