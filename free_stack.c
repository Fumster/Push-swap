#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_stack *tmp;

    tmp = NULL;
	while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}

void free_stacks(t_list *stacks)
{
if (stacks && stacks->stack_a)
	free_stack(stacks->stack_a);
if (stacks && stacks->stack_b)
	free_stack(stacks->stack_b);
}
