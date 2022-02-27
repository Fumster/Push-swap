#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // DELETE<<<<<<<<<<<<<<<<<<<<<<<<

typedef struct s_list
{
	int				num;
	int				index;
	int				gen;
	int				sorted;
	struct s_list	*next;
}					t_list;

void	validate (int argc, char **argv);
int		count_nbrs(int argc, char **argv);
t_list	*parse (int argc, char **argv);
void	free_stack(t_list *stack);
void	ft_error (t_list *stack_a, t_list *stack_b);
void	check_duplicates (t_list *stack);
void	index_lists (int nbr_cntr, t_list *stack);



#endif
