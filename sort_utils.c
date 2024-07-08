/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:19:59 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/08 17:02:30 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	if (!temp || !temp->content)
		return (FALSE);
	while (temp->next != NULL)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

int	get_min_value(t_list *stack_a)
{
	t_list	*temp;
	int		min_value;

	temp = stack_a;
	if (!temp)
		ft_error("Error\n");
	min_value = *(int *)temp->content;
	while (temp && temp->next)
	{
		if (min_value > *(int *)temp->next->content)
			min_value = *(int *)temp->next->content;
		temp = temp->next;
	}
	return (min_value);
}

int	get_max_value(t_list *stack_a)
{
	t_list	*temp;
	int		max_value;

	temp = stack_a;
	if (!temp)
		ft_error("Error\n");
	max_value = *(int *)temp->content;
	while (temp && temp->next)
	{
		if (max_value < *(int *)temp->next->content)
			max_value = *(int *)temp->next->content;
		temp = temp->next;
	}
	return (max_value);
}

int	get_direction(t_list *stack, int content)
{
	t_list	*temp;
	int		list_size;
	int		i;

	i = 0;
	temp = stack;
	if (!temp)
		ft_error("Error\n");
	while (temp && *(int *)temp->content != content && temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	list_size = ft_lstsize(stack);
	if (i > (list_size / 2))
		return (i - list_size);
	return (i);
}

int	get_chunk_size(t_list *stack_a)
{
	if (ft_lstsize(stack_a) <= 20)
		return (5);
	else if (ft_lstsize(stack_a) <= 50)
		return (10);
	else if (ft_lstsize(stack_a) <= 100)
		return (20);
	else if (ft_lstsize(stack_a) <= 200)
		return (35);
	else if (ft_lstsize(stack_a) <= 350)
		return (42);
	else if (ft_lstsize(stack_a) <= 500)
		return (50);
	else if (ft_lstsize(stack_a) <= 700)
		return (60);
	else
		return (100);
}
