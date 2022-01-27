/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/27 21:44:11 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int parse_string (char *str, int *arr)
{
	int	i;
	int len;

	
	while (str[i])
	{
		
	}
	return (pos);
}

int	count_nbrs(int str_nbr, char **str)
{
	int s;
	int c;
	int cntr;
	int is_num;

	s = 0;
	c = 0;
	cntr = 0;
	is_num = 0;
	while (s <= str_nbr)
	{
		while (str[s][c])
		{
			if (str[s][c] >= '0' && str[s][c] <= '9' && is_num == 0)
				cntr++;
			if (str[s][c] >= '0' && str[s][c] <= '9')
				is_num = 1;
			else
				is_num = 0;
			c++;
		}
		s++;
	}
	return (cntr);
}

int	parse (int argc, char **argv, int *arr)
{
	int	nbr_cntr;
	int	s;

	s = 0;
	nbr_cntr = count_nbrs(argc - 2, **argv);
	arr = malloc(sizeof (int) * nbr_cntr);
	if (!arr)
		return (0);
	while (s < argc - 2)
	{
		parse_string(argv[s], ret_arr);
		s++;		
	}
	return (nbr_cntr);
}
