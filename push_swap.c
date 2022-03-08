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

void	test (t_list *stacks)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		i;
	int		a_n;
	int		a_i;
	int 	b_n;
	int 	b_i;
	int 	a_g;
	int 	b_g;

	tmp_a = stacks->stack_a;
	tmp_b = stacks->stack_b;
	i = 1;
	printf("----------- stack a --------------|----------- stack b ---------\n");
	while (tmp_a || tmp_b)
	{
		a_n = 0;
		a_i = 0;
		b_n = 0;
		b_i = 0;
		a_g = 0;
		b_g = 0;
		if (tmp_a)
		{
			a_n = tmp_a->num;
			a_i = tmp_a->index;
			a_g = tmp_a->gen;
		}
		if (tmp_b)
		{
			b_n = tmp_b->num;
			b_i = tmp_b->index;
			b_g = tmp_b->gen;
		}
		printf	("%3.d. num=%5.d index=%3.d gen=%2.d | num=%5.d index=%3.d gen=%2.d\n",
				i, a_n, a_i, a_g, b_n, b_i, b_g);
		if(tmp_a)
			tmp_a = tmp_a->next;
		if(tmp_b)
			tmp_b = tmp_b->next;
		i++;
	}
}

int main (int	argc, char **argv)
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
		//printf ("nbr_cntr is %d\n", nbr_cntr); // remove
		parse(argc, argv, &stacks);
		check_duplicates(&stacks);
		index_lists(nbr_cntr, &stacks);
		test(&stacks); // remove
		sorted = is_sorted(&stacks);
		if (!sorted)
			sort_stack(nbr_cntr, &stacks);
		test(&stacks); // remove
		free_stacks(&stacks);
	}	
	return (0);
}
