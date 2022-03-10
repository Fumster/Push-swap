#include"push_swap.h"

int find_min_num (t_stack *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (stack->num <= min && stack->index == 0)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

void index_lists (int nbr_cntr, t_list *stacks)
{
	int	index;
	int	min;
	t_stack *tmp;
	
	index = 1;
	tmp = stacks->stack_a;
	while (index <= nbr_cntr)
	{
		min = find_min_num(stacks->stack_a);
		while (tmp->num != min)
			tmp = tmp->next;
		tmp->index = index;
		tmp = stacks->stack_a;
		index++;
	}
}
