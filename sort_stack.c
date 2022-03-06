#include "push_swap.h"

void	sort_stack (int nbr_cntr, t_list *stacks)
{
	if(nbr_cntr <= 3)
		sort_3_el(stacks);
	else if(nbr_cntr <= 5)
		sort_5_el(stacks);
	else
		sort_max_el(stacks, nbr_cntr);
}
