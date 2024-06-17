/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:13:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/17 07:38:30 by jfarnos-         ###   ########.fr       */
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

void print_list(t_list *stack)
{
    t_list *current;
    
    current = stack;
    while (current)
    {
        printf("%i\n", *(int *)current->content);
        current = current->next;
    }
}

void check_int_range(long value, t_list *stack)
{
		if (value < -2147483648 || value > 2147483647)
		{
			ft_lstclear(&stack, &free);
			ft_error("Error\n");
		}
}

void check_duplicated_int(t_list *stack)
{
	t_list *current;
	t_list	*runner;
	long	value;
	
	if(!stack)
		ft_error("Error\n");
	current = stack;
	while (current)
	{
		value = *((long *)current->content);
		runner = current->next;
		while(runner)
		{
			if (*((long *)current->content) == *((long *)runner->content))
			{
				ft_lstclear(&stack, &free);
				ft_error("Error\n");
			}
			runner = runner->next;
		}
		check_int_range(value, stack);
		current = current->next;
	}
}
