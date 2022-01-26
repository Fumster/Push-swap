#include "push_swap.h"

int main (int	argc, char **argv)
{
	int	*unsorted_arr;
	int	*indexes_arr;
	int	nbrs_amnt;
	t_list	*stack_a;
	t_list	*stack_b;

	unsorted_arr = NULL;
	nbrs_amnt = parse(argc, argv, unsorted_arr);
	indexes_arr = sort_arr(unsorted_arr, nbrs_amnt);
	fill_stack(sorted_arr, stack_a);
	sort_stack(stack_a, stack_b, nbrs_amnt);
	return (0);
}
