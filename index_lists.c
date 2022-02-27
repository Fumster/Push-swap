#include"push_swap.h"

int find_min (t_list *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (stack->num < min && stack->index == 0)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

void index_lists (int nbr_cntr, t_list *stack)
{
	int	index;
	int	min;
	t_list *tmp;
	
	index = 1;
	tmp = stack;
	while (index <= nbr_cntr)
	{
		min = find_min(stack);
		while (tmp->num != min)
			tmp = tmp->next;
		tmp->index = index;
		tmp = stack;
		index++;
	}
}
