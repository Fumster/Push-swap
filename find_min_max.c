/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:22:35 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/10 20:59:08 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min (t_stack *stack)
{
    int min;

    min = 2147483647;
    while(stack)
    {
        if (stack->index < min)
			min = stack->index;
		stack = stack->next;
    }
    return (min);
}

int find_max (t_stack *stack)
{
    int max;

    max = 0;
    while(stack)
    {
        if (stack->index > max)
			max = stack->index;
		stack = stack->next;
    }
    return (max);
}
