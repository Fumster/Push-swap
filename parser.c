/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/28 21:18:21 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add_list(long int num, t_list *stack)
{
	
}

int	ft_atoi(char *str, t_list *stack)
{
	int			sign;
	int			i;
	long int	num;

	sign = 1;
	i = 0;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' || str[i] <= '9' || str[i] == '-')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	num = num * sign;
	add_list(num, stack);
	return (i);
}

int parse_string (char *str, int *arr, t_list *stack)
{
	int	i;
	int len;

	
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')
			str + ft_atoi(str, stack);
		else
			str++;
	}
	return (pos);
}

int	parse (int argc, char **argv, t_list *stack)
{
	int	s;

	s = 0;
	while (s < argc - 2)
	{
		parse_string(argv[s], ret_arr, stack);
		s++;		
	}
	return (0);
}
