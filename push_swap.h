#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // DELETE<<<<<<<<<<<<<<<<<<<<<<<<

typedef struct s_list
{
	int	index;
	int	gen;
	int	sorted;
}	t_list;

int validate (int argc, char **argv);
int count_nbrs(int argc, char **argv);
int parse (int argc, char **argv, t_list *stack);

#endif
