/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:00:41 by jfrancis          #+#    #+#             */
/*   Updated: 2022/07/11 21:36:32 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	validate_number(char **argv, int i)
{
	long int	j;
	int			index;
	int			arg_size;

	j = 0;
	index = 0;
	arg_size = ft_strlen(argv[i]);
	if (argv[i][index] == '-')
		index++;
	while (index < arg_size)
	{
		if (!ft_isdigit(argv[i][index]))
			print_error("All arguments must be numbers.");
		index++;
	}
	j = ft_atol(argv[i]);
	if (j > MAX_INT || j < MIN_INT)
		print_error(data);
	return (j);
}

int	check_params(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	if (argc < 5 || argc > 6)
		return (print_error("philos must have at least 4 arguments."));
	while (i < argc)
	{
		validate_number(argv, i);
	}
	return (0);
}
