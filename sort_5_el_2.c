#include "push_swap.h"

void	sort_5_el (t_list *stacks)
{
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sort_3_el(stacks);
		pb(stacks);
		pb(stacks);
		sort_3_el(stacks);
		pa(stacks);
		sort_3_el(stacks);
		//if (stacks->stack_a->index > stacks->stack_a->next->index)
		//	ra(stacks);
		pa(stacks);
		sort_3_el(stacks);
		//if (stacks->stack_a->index > stacks->stack_a->next->index)
		//	ra(stacks);
		sorted = is_sorted(stacks);
	}
}
