/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:09:58 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/14 15:10:29 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	bring_to_top_b(t_list **stack_a, t_list **stack_b, int value, int previous)
{
	int	flag;

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