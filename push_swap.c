#include "push_swap.h"

int main (int	cntr, char **argv)
{
	int	*unsorted_arr;
	int	*indexes_arr;
	t_list	*stack_a;

	unsorted_arr = NULL;
	if (cntr > 1)
	{
		cntr = validate(cntr, argv);
		cntr = parse(cntr, argv, unsorted_arr);
		if (!cntr)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		indexes_arr = sort_arr(unsorted_arr, cntr);
		fill_stack(sorted_arr, stack_a);
		sort_stack(stack_a, stack_b, cntr);
	}	
	return (0);
}
