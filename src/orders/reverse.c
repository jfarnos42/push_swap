/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 04:35:50 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/14 15:05:07 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	second_last = *stack_a;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	ft_lstadd_front(stack_a, last);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	second_last = *stack_b;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	ft_lstadd_front(stack_b, last);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
