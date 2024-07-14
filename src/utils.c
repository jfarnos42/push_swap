/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:13:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/14 15:03:23 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	print_list(t_list *stack)
// {
// 	t_list	*current;

// 	current = stack;
// 	while (current)
// 	{
// 		printf("%i\n", *(int *)current->content);
// 		current = current->next;
// 	}
// }

// void	print_chunk(char **chunk, int chunk_size)
// {
// 	int	i;

// 	for (i = 0; i < chunk_size; i++)
// 	{
// 		printf("%s\n", chunk[i]);
// 	}
// }

void	ft_error(char *string_error)
{
	int	i;

	i = 0;
	while (string_error[i])
	{
		write(2, &string_error[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	check_int_range(long value, t_list *stack)
{
	if (value < -2147483648 || value > 2147483647)
	{
		ft_lstclear(&stack, &free);
		ft_error("Error\n");
	}
}

void	check_duplicated_int(t_list *stack)
{
	t_list	*current;
	t_list	*runner;
	long	value;

	if (!stack)
		ft_error("Error\n");
	current = stack;
	while (current)
	{
		value = *((long *)current->content);
		runner = current->next;
		while (runner)
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
