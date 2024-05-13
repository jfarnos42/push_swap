/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:59:45 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/05/13 18:14:06 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main_cheater(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
	{
		write(1, "Not enough Arguments\n", 21);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (main_cheater(argc, argv) == 1)
		exit(EXIT_FAILURE);
	stacks = args_to_stack(argc, argv);
	if (stacks == NULL)
		return (1);
	check_node_data(&stacks);


	return (0);
}
