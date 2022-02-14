/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nbr.                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/28 21:18:21 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void count_nbrs(int argc, char **argv, int *cntr)
{
    int s;
    int c;
    int is_num;

    s = 1;
    c = 0;
    is_num = 0;
	printf ("argc %d\n", argc);
    while (s < argc)
    {
        while (argv[s][c])
        {
            if (argv[s][c] >= '0' && argv[s][c] <= '9' && is_num == 0)
                *cntr = *cntr + 1;
            if (argv[s][c] >= '0' && argv[s][c] <= '9')
                is_num = 1;
            else
                is_num = 0;
            c++;
        }
		is_num = 0;
        c = 0;
		s++;
    }
}
