/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:13:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/04/26 04:22:48 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	init_stacks(t_stacks **stacks)
{
	*stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (*stacks == NULL)
	{
		write(1, "INIT_STACKS: Memory allocation failed\n", 38);
		exit(EXIT_FAILURE);
	}
	(*stacks)->stack_a = NULL;
	(*stacks)->stack_b = NULL;
}


void	print_stack(t_stacks *stacks)
{
	t_node	*node;

	node = stacks->stack_a;
	while (node)
	{
		printf("array: %i\n", node->number);
		node = node->next;
	}
}

t_node	*pushswap_new_node(int number)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}
