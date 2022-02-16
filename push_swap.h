#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // DELETE<<<<<<<<<<<<<<<<<<<<<<<<

typedef struct s_list
{
	long int		num;
	int				index;
	int				gen;
	int				sorted;
	struct s_list	*next;
}					t_list;

void validate (int argc, char **argv);
void count_nbrs(int argc, char **argv, int *cntr);
int parse (int argc, char **argv, t_list *stack);
void free_stack(t_list *stack);

#endif
