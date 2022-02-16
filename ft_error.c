/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/28 21:18:21 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void free_stack(t_list *stack)
{
	t_list *tmp;

	next = NULL;
	while (stack)
	{
	tmp = stack->next;
	free(stack);
	stack = tmp;
	}
}

void ft_error (t_list *stack_a, t_list *stack_b)
{
	if(stack_a)
		free_stack(stack_a);
	if(stack_b)
		free_stack(stack_b);
	write(1, "Error\n", 6);
	exit (1);
}