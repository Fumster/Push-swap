/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:45:25 by fchrysta          #+#    #+#             */
/*   Updated: 2022/01/28 21:18:21 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int validate_string (char *s)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	while (s[i])
	{
		if ((digit > 11) || \
		((s[i] < '0' || s[i] > '9') && (s[i] != "-") && (s[i] != " ")) || \
		((s[i] >= '0' && s[i] <= '9') && \
		 s[i + 1] == '-') || \
		(s[i] == '-' && (s[i + 1] == " " || \
		s[i + 1] == 0 || s[i + 1] == "-")))
			return (0);
		i++;
		digit++;
		if (s[i] == ' ')
			digit = 0;
	}
	return (1);
}

int validate (int argc, char **argv)
{
	int	s;
	int	valid;

	valid = 0;
	s = 1;
	while (s < argc)
	{
		valid = validate_string(argv[s]);
		if (valid == 0)
			return(0);
		s++;
	}
	return (1);
}
