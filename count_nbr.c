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

int count_num_str (char *str)
{
	int	i;
	int	is_num;
	int	num;

	i = 0;
	is_num = 0;
	num = 0;
	while (str[i])
	{
	if (str[i] >= '0' && str[i] <= '9' && is_num == 0)
		num++;
	if (str[i] >= '0' && str[i] <= '9')
		is_num = 1;
	else
		is_num = 0;
	i++;
	}
	return (num);
}

int count_nbrs(int argc, char **argv)
{
    int s;
	int num;

    s = 1;
	num = 0;
    while (s < argc)
    {
		num = num + count_num_str(argv[s]);
		s++;
    }
	if (!num)
		ft_error (NULL, NULL);
	return (num);
}
