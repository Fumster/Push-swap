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

void	test (t_list *stack_a)
{
	t_list	*tmp_a;
	int		i;

	tmp_a = stack_a;
	i = 1;
	printf("------- stack a ------\n");
	while (tmp_a)
	{
		printf("%d. num = %d, index = %d\n", i, tmp_a->num, tmp_a->index);
		tmp_a = tmp_a->next;
		i++;
	}
}

int main (int	argc, char **argv)
{
	t_list	*stack_a;
//	t_list	*stack_b;
	int		nbr_cntr;

	if (argc > 1)
	{
		validate(argc, argv);
		nbr_cntr = count_nbrs(argc, argv);
		printf ("nbr_cntr is %d\n", nbr_cntr);
		stack_a = parse(argc, argv);
		check_duplicates(stack_a);
		index_lists(nbr_cntr, stack_a);
		test(stack_a); // remove
		free_stack(stack_a);
	}	
	return (0);
}
