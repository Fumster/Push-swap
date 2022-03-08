#include "push_swap.h"

int rev_rotate_stack (t_stack **stack)
{
	t_stack	*first;
	t_stack *last;
	t_stack	*penult;

	first = *stack;
	last = *stack;
	penult = *stack;
	while (last && last->next)
		last = last->next;
	while (penult && penult->next->next)
		penult = penult->next;
	if(first && first->next)
	{
		*stack = last;
		last->next = first;
		penult->next = NULL;
		return (0);
	}
	return (1);
}

void rra (t_list *stacks)
{
	int err;
	
	err = rev_rotate_stack (&stacks->stack_a);
	if (!err)
		write(1, "rra\n", 4);
}

void rrb (t_list *stacks)
{
	int err;
	
	err = rev_rotate_stack (&stacks->stack_b);
	if (!err)
		write(1, "rrb\n", 4);
}

void rrr (t_list *stacks)
{
	int err;
	
	err = rev_rotate_stack (&stacks->stack_a);
	err += rev_rotate_stack (&stacks->stack_b);
	if (!err)
		write(1, "rrr\n", 4);
}
