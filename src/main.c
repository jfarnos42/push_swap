/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:59:45 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/14 15:28:44 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*generate_list(char **argv, t_list *stack_a)
{
	t_list	*stack;
	t_list	*new_node;
	int		i;

	stack = stack_a;
	if (!argv)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv[++i])
	{
		new_node = check_str_format(argv[i]);
		if (new_node)
			ft_lstadd_back(&stack, new_node);
	}
	new_node = NULL;
	check_duplicated_int(stack);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	stack_a = generate_list(argv, stack_a);
	push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	return (0);
}
