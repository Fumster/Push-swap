/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:10:43 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 18:13:49 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				gen;
	int				sorted;
	struct s_stack	*next;
}					t_stack;

typedef struct s_list
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_list;

void	validate(int argc, char **argv);
int		count_nbrs(int argc, char **argv);
void	parse(int argc, char **argv, t_list *stacks);
void	free_stacks(t_list *stacks);
void	ft_error(t_list *stacks);
void	check_duplicates(t_list *stacks);
void	index_lists(int nbr_cntr, t_list *stacks);
void	sa(t_list *stacks);
void	sb(t_list *stacks);
void	ss(t_list *stacks);
void	pa(t_list *stacks);
void	pb(t_list *stacks);
void	ra(t_list *stacks);
void	rb(t_list *stacks);
void	rr(t_list *stacks);
void	rra(t_list *stacks);
void	rrb(t_list *stacks);
void	rrr(t_list *stacks);
int		is_sorted(t_list *stacks);
void	sort_stack(int nbr_cntr, t_list *stacks);
void	sort_3_el(t_list *stacks);
void	sort_5_el(t_list *stacks, int cntr);
void	sort_max_el(t_list *stacks, int max_order);
int		count_stack(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_last_index(t_stack *stack);
int		find_last_gen(t_stack *stack);

#endif
