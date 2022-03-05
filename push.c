#include "push_swap.h"

void push (t_stack **dst, t_stack **src)
{
	t_stack	*tmp;
	
	tmp = *src;
	if(*src)
	{
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}

void pa (t_list *stacks)
{
	push (&stacks->stack_a, &stacks->stack_b);
}

void pb (t_list *stacks)
{
	push (&stacks->stack_b, &stacks->stack_a);
}
