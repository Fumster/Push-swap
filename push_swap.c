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
	t_list	stack_a;
	int		nbr_cntr;
	int		valid;

	nbr_cntr = 0;
	if (argc > 1)
	{
		count_nbrs(argc, argv, &nbr_cntr);
		printf ("nbr_cntr is %d\n", nbr_cntr);
		valid = validate(argc, argv);
		if (!nbr_cntr || !valid)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		parse(argc, argv, &stack_a);
		//sort_stack(stack_a, nbr_cntr);
	}	
	return (0);
}
