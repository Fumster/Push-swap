/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:55:39 by fchrysta          #+#    #+#             */
/*   Updated: 2022/03/13 18:56:17 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(int nbr_cntr, t_list *stacks)
{
	if (nbr_cntr <= 3)
		sort_3_el(stacks);
	else if (nbr_cntr <= 5)
		sort_5_el(stacks, nbr_cntr);
	else
		sort_max_el(stacks, nbr_cntr);
}
