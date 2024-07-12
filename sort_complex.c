/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:00:56 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/12 20:17:38 by jfarnos-         ###   ########.fr       */
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

int	bring_to_top_b(t_list **stack_a, t_list **stack_b, int value,
		int previous)
{
	int flag;

	if (value == previous)
		return (0);
	flag = 0;
	while (get_direction(*stack_b, value) != 0)
	{
		if (previous == get_top_value(*stack_b))
		{
			pa(stack_a, stack_b);
			flag = 1;
		}
		if (get_direction(*stack_b, value) > 0)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	return (flag);
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

int	is_in_chunk(int value, char **index, int chunk_size)
{
	int	i;

	i = 0;
	while (index[i] && i < chunk_size)
	{
		if (value == ft_atoi(index[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	is_chunk_complited(t_list *stack_a, char **index, int chunk_size)
{
	t_list	*temp;
	int		value;
	int		i;

	temp = stack_a;
	if (!temp)
		return (TRUE);
	i = 0;
	while (i < chunk_size)
	{
		while (temp)
		{
			value = *(int *)temp->content;
			if (ft_atoi(index[i]) == value)
				return (FALSE);
			temp = temp->next;
		}
		temp = stack_a;
		i++;
	}
	return (TRUE);
}

void	sort_chunk(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	char	**index;
	int		top_a;
	int		i;

	index = create_chunk(*stack_a, ft_lstsize(*stack_a));
	sort_chunk_array(index, ft_argc(index));
	i = 0;
	while (!is_chunk_complited(*stack_a, index, chunk_size) && index[i])
	{
		top_a = get_top_value(*stack_a);
		if (is_in_chunk(top_a, index, chunk_size) == TRUE)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	ft_freematrix(index, ft_argc(index));
}

void	merge_chunks(t_list **stack_a, t_list **stack_b, char **index)
{
	int	target;
	int shortcut;
	int	i;

	i = ft_argc(index) - 1;
	while (*stack_b)
	{
		target = ft_atoi(index[i]);
		if (i == 0)
			shortcut = bring_to_top_b(stack_a, stack_b, target, target);
		else
			shortcut = bring_to_top_b(stack_a, stack_b, target, ft_atoi(index[i - 1]));
		pa(stack_a, stack_b);
		if (shortcut == 1)
			sa(*stack_a);
		i--;
		i -= shortcut;
	}
}

void	sort_complex(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	char	**index;
	int		chunk_size;

	chunk_size = ft_lstsize(*stack_a) / get_chunk_size(*stack_a);
	index = create_chunk(*stack_a, ft_lstsize(*stack_a));
	temp = *stack_a;
	if (!index && !temp)
		ft_error("Error\n");
	sort_chunk_array(index, ft_argc(index));
	if (!is_sorted(*stack_a) && !(*stack_b))
	{
		while (ft_lstsize(*stack_a))
			sort_chunk(stack_a, stack_b, chunk_size);
		merge_chunks(stack_a, stack_b, index);
	}
	ft_freematrix(index, ft_argc(index));
	ft_lstclear(stack_a, &free);
}
