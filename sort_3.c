/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 04:57:29 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/08 05:05:41 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	apply_sort_operations(t_list **stack_a, int a, int b, int c)
{
	if (a > b && a < c)
		sa(*stack_a);
	else if (a < b && b > c)
		rra(stack_a);
	else if (a > c && b < c)
		ra(stack_a);
	else if (a > b && b > c)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (a < b && a > c)
	{
		sa(*stack_a);
		ra(stack_a);
	}
}

void	sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!(*stack_a) || !(*stack_a)->content || is_sorted((*stack_a)))
		return ;
	while (!is_sorted(*stack_a))
	{
		a = *(int *)(*stack_a)->content;
		b = *(int *)(*stack_a)->next->content;
		c = *(int *)(*stack_a)->next->next->content;
		apply_sort_operations(stack_a, a, b, c);
	}
}
