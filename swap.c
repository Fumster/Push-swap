#include "push_swap.h"

void swap_stack (t_stack **stack)
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
	}
}

void sa (t_list *stacks)
{
	swap_stack (&stacks->stack_a);
}

void sb (t_list *stacks)
{
	swap_stack (&stacks->stack_b);
}

void ss (t_list *stacks)
{
	swap_stack (&stacks->stack_a);
	swap_stack (&stacks->stack_b);
}
