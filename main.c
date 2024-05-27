/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:59:45 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/05/27 22:40:27 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_node *generate_list(char **argv, t_node *stack_a)
{
	t_node *stack;
	t_node *new_node;
    int i;

	stack = stack_a;
	if(!argv)
        exit(EXIT_FAILURE);
	i = 1;
    while (argv[i])
	{
        new_node = check_str_format(argv[i]);
        if (new_node)
           pushswap_add_last(&stack, new_node);
        i++;
    }
    check_duplicated_int(stack);
	return(stack);
}

void print_list(t_node *stack)
{
    t_node *current;
    
    current = stack;
    while (current)
    {
        printf("%d\n", current->number);
        current = current->next;
    }
}


int	main(int argc, char **argv)
{
    t_node *stack_a;
	t_node *stack_b;

    if (argc <= 1)
        return (1);
    (void)stack_b;
    stack_a = NULL;
    stack_a = generate_list(argv, stack_a);
    print_list(stack_a);

    return (0);
}