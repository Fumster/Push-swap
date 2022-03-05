#include "push_swap.h"

void swap_stack (t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	stack = stack->next;
	stack->next = tmp;
}

void swap (t_list *stack_1, t_list *stack_2)
{
	if (stack_1 && stack_1->next)
		swap_stack(stack_1);
	if (stack_2 && stack_2->next)
		swap_stack(stack_2);
}

void sa (t_list *stack_a)
{
	swap (stack_a, NULL);
}

void sb (t_list *stack_b)
{
	swap (stack_b, NULL);
}

void ss (t_list *stack_a, t_list *stack_b)
{
	swap (stack_a, stack_b);
}
