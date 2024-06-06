/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:13:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/06 22:44:26 by jfarnos-         ###   ########.fr       */
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

void check_duplicated_int(t_list *stack)
{
	t_list *current;
	t_list	*runner;
	
	if(!stack)
		ft_error("List is EMPTY!\nTerminating...\n");
	current = stack;
	while (current)
	{
		runner = current->next;
		while(runner)
		{
			if (*((int *)current->content) == *((int *)runner->content))
			{
				ft_lstclear(&stack, &free);
				ft_error("Duplicated INT found\nTerminating...\n");
			}
			runner = runner->next;
		}
		current = current->next;
	}
}
