/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:00:56 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/10 10:01:15 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_chunk_array(char **chunk, int chunk_size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < chunk_size - 1 && chunk[i] != NULL)
	{
		j = i + 1;
		while (j < chunk_size && chunk[j] != NULL)
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

int	get_bottom_value(t_list *stack)
{
	t_list	*temp;
	int		value;

	temp = stack;
	if (!temp)
		ft_error("Error3\n");
	temp = ft_lstlast(temp);
	value = *(int *)(temp)->content;
	return (value);
}

int	get_top_value(t_list *stack)
{
	t_list	*temp;
	int		value;

	temp = stack;
	if (!temp)
		ft_error("Error2\n");
	value = *(int *)(temp)->content;
	return (value);
}

void	bring_to_top_a(t_list **stack, int value)
{
	while (get_direction(*stack, value) != 0)
	{
		if (get_direction(*stack, value) > 0)
			ra(stack);
		else
			rra(stack);
	}
}

void	bring_to_top_b(t_list **stack, int value)
{
	while (get_direction(*stack, value) != 0)
	{
		if (get_direction(*stack, value) > 0)
			rb(stack);
		else
			rrb(stack);
	}
}

int	get_index(char **index, int value)
{
	int	i;

	i = 0;
	while (index[i])
	{
		if (ft_atoi(index[i]) == value)
			i++;
	}
	return (i);
}

char	**create_chunk(t_list *stack_a, int chunk_size)
{
	t_list	*temp;
	char	**chunk;
	int		i;

	temp = stack_a;
	chunk = (char **)malloc((chunk_size + 1) * sizeof(char *));
	if (!chunk || !temp)
		ft_error("Error1\n");
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

void	sort_chunks(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	char	**chunk;
	int		i;
	int		value;

	chunk = create_chunk(*stack_a, chunk_size);
	sort_chunk_array(chunk, ft_argc(chunk));
	i = 0;
	while (chunk[i] && ft_lstsize(*stack_a))
	{
		value = ft_atoi(chunk[i]);
		bring_to_top_a(stack_a, value);
		pb(stack_b, stack_a);
		i++;
	}
	ft_freematrix(chunk, ft_argc(chunk));
}


void	merge_chunks(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int	value;

	(void)chunk_size;
	while (*stack_b || (!is_sorted(*stack_a) && ft_lstsize(*stack_b) > 0))
	{
		value = *(int *)(*stack_b)->content;
		if(!stack_a && value < get_bottom_value(*stack_a))
			rra(stack_a);
		else
			pa(stack_a, stack_b);
	}
}

void	sort_complex(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		chunk_size;

	chunk_size = get_chunk_size(*stack_a);
	chunk_size = ft_lstsize(*stack_a) / chunk_size;
	// printf("Chunk_size: %i\n", chunk_size);
	temp = *stack_a;
	if (!temp)
		ft_error("Error\n");
	if (!is_sorted(*stack_a) && !(*stack_b))
	{
		while (ft_lstsize(*stack_a))
			sort_chunks(stack_a, stack_b, chunk_size);
		merge_chunks(stack_a, stack_b, chunk_size);
	}
	ft_lstclear(stack_a, &free);
}
