/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/28 21:18:21 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int	argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		nbr_cntr;

	nbr_cntr = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		validate(argc, argv);
		count_nbrs(argc, argv, &nbr_cntr);
		printf ("nbr_cntr is %d\n", nbr_cntr);
		if (!nbr_cntr)
			ft_error(stack_a, stack_b);
		parse(argc, argv, stack_a);
		//sort_stack(stack_a, nbr_cntr);
	}	
	return (0);
}
