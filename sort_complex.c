/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:00:56 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/08 16:51:49 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_chunk_array(char **chunk, int chunk_size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < chunk_size - 1)
	{
		j = i + 1;
		while (j < chunk_size)
		{
			if (ft_atoi(chunk[j]) < ft_atoi(chunk[i]))
			{
				temp = chunk[i];
				chunk[i] = chunk[j];
				chunk[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	bring_to_top(t_list **stack, int value)
{
	while (get_direction(*stack, value) != 0)
	{
		if (get_direction(*stack, value) > 0)
			rb(stack);
		else
			rrb(stack);
	}
}

char	**create_chunk(t_list *stack_a, int chunk_size)
{
	t_list	*temp;
	char	**chunk;
	int		i;

	chunk = (char **)malloc((chunk_size + 1) * sizeof(char *));
	if (!chunk)
		ft_error("Error\n");
	temp = stack_a;
	i = 0;
	while (temp && i < chunk_size)
	{
		chunk[i] = ft_itoa(*(int *)temp->content);
		temp = temp->next;
		i++;
	}
	chunk[i] = NULL;
	return (chunk);
}

void	sort_chunks(t_list **stack_a, t_list **stack_b)
{
	int		chunk_size;
	char	**chunk;
	int		i;
	int		value;

	chunk_size = get_chunk_size(*stack_a);
	chunk = create_chunk(*stack_a, chunk_size);
	sort_chunk_array(chunk, chunk_size);
	i = 0;
	while (chunk[i] && ft_lstsize(*stack_a) != 0)
	{
		value = ft_atoi(chunk[i]);
		while (*stack_a && *(int *)(*stack_a)->content != value)
		{
			if (get_direction(*stack_a, value) > 0)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
		i++;
	}
	ft_freematrix(chunk, chunk_size);
}

void	merge_chunks(t_list **stack_a, t_list **stack_b)
{
	int value;
	
	while(ft_lstsize(*stack_b) != 0 || (!is_sorted(*stack_a) && ft_lstsize(*stack_b) != 0))
	{
		value = get_max_value(*stack_b);
		bring_to_top(stack_b, value);
		pa(stack_a, stack_b);	
	}
}

void	sort_complex(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	(void)stack_b;
	temp = *stack_a;
	if (!temp)
		ft_error("Error\n");
	if (!is_sorted(*stack_a) && !(*stack_b))
	{
		while (ft_lstsize(*stack_a) != 0)
			sort_chunks(stack_a, stack_b);
		merge_chunks(stack_a, stack_b);
	}
	return ;
}
