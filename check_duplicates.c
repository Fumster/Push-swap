#include "push_swap.h"

void	check_duplicates(t_list *stack)
{
	t_list	*next;

	next = stack->next;
	while (stack->next)
	{
		while (next)
		{
			if (stack->num == next->num)
			ft_error(stack, NULL);
			next = next->next;
		}
		stack = stack->next;
		next = stack->next;
	}
}
