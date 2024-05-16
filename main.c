/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:59:45 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/05/16 20:57:13 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stacks *check_raw_args(t_stacks *stack, int argc, char **argv)
{
	int i;
	
	i = 0;
	while (++i <= argc)
	{
		if (check_nonvalid_char(argv[i]) == 1)
			return (NULL);
		
		else
			args_to_stack(ft_atoi(argv[i]));
	}
	return (stack)
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	check_raw_args(stacks , argc, argv);
	
	
	return (0);
}
