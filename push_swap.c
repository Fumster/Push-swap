#include "push_swap.h"

int main (int	argc, char **argv)
{
	t_list	*stack_a;
	int		nbr_cntr;
	int		valid;

	if (argc > 1)
	{
		nbr_cntr = count_nbr(argc, argv);
		valid = validate(argc, argv, nbr_cntr);
		if (!cntr || !valid)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		parse(argc, argv, nbr_cntr, stack_a);
		sort_stack(stack_a, nbr_cntr);
	}	
	return (0);
}
