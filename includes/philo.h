/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:24:11 by jfrancis          #+#    #+#             */
/*   Updated: 2022/07/11 21:37:46 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <colors.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_philos
{
	int	num_philos;
	int	forks;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
}	t_philos

// utils
int	print_error(char *msg);
int	check_params(int argc, char **argv);

#endif