/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:10:48 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/08 05:29:46 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	list_size;

	if (!stack_a || !stack_b)
		ft_error("Error");
	list_size = ft_lstsize(*stack_a);
	if (list_size == 2)
		sort_2(stack_a);
	else if (list_size == 3)
		sort_3(stack_a);
	else if (list_size <= 5 && list_size > 3)
		sort_5(stack_a, stack_b);
	else
		sort_complex(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	while (ft_lstsize(*stack_a) > 3)
	{
		while (get_direction(*stack_a, get_min_value(*stack_a)) != 0)
		{
			if (get_direction(*stack_a, get_min_value(*stack_a)) > 0)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_2(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	if (!temp || is_sorted(*stack_a))
		return ;
	ra(stack_a);
}
