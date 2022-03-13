/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 18:10:25 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stacks;
	int		nbr_cntr;
	int		sorted;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	sorted = 0;
	if (argc > 1)
	{
		validate(argc, argv);
		nbr_cntr = count_nbrs(argc, argv);
		parse(argc, argv, &stacks);
		check_duplicates(&stacks);
		index_lists(nbr_cntr, &stacks);
		sorted = is_sorted(&stacks);
		if (!sorted)
			sort_stack(nbr_cntr, &stacks);
		free_stacks(&stacks);
	}	
	return (0);
}
