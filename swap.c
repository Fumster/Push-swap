#include "push_swap.h"

int swap_stack (t_stack **stack)
{
	t_stack	*first;
	t_stack *second;
	t_stack *third;

	first = *stack;
	if(*stack && (*stack)->next)
	{
		second = (*stack)->next;
		third = (*stack)->next->next;
		*stack = second;
		(*stack)->next = first;
		(*stack)->next->next = third;
		return (0);
	}
	return (1);
}

void sa (t_list *stacks)
{
	int err;
	
	err = swap_stack (&stacks->stack_a);
	if (!err)
		write(1, "sa\n", 3);
}

void sb (t_list *stacks)
{
	int err;
	
	err = swap_stack (&stacks->stack_b);
	if (!err)
		write(1, "sb\n", 3);
}

void ss (t_list *stacks)
{
	int err;
	
	err = swap_stack (&stacks->stack_a);
	err += swap_stack (&stacks->stack_b);
	if (!err)
		write(1, "ss\n", 3);
}
