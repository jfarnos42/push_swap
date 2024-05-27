/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:13:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/05/27 22:36:12 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void ft_error(char *string_error)
{
    int i;

    i = 0;
    while(string_error[i])
    {
        write(1, &string_error[i], 1);
        i++;
    }
    exit(EXIT_FAILURE);
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

void	pushswap_add_last(t_node **stack, t_node *node)
{
	t_node	*p_aux;

	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	p_aux = *stack;
	if (node)
	{
		while (p_aux->next != NULL)
			p_aux = p_aux->next;
		p_aux->next = node;
	}
}
void check_duplicated_int(t_node *stack)
{
	t_node *current;
	t_node	*runner;
	
	if(!stack)
		ft_error("List is EMPTY!\nTerminating...\n");
	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while(runner != NULL)
		{
			if (current->number == runner->number)
			{
				free(stack);
				ft_error("Duplicated INT found\nTerminating...\n");
			}
			runner = runner->next;
		}
		current = current->next;
	}
}