#include"push_swap.h"

int	is_sorted (t_list *stacks)
{
	t_stack	*stack;

	stack = stacks->stack_a;
	while(stack->next)
	{
		if(stack->index < stack->next->index)
			stack = stack->next;
		else
			return(0);
	}
	return(1);
}
