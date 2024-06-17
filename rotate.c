/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 04:35:52 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/17 06:17:20 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void ra(t_list **stack_a)
{
    t_list *temp;
    
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = NULL;
    ft_lstadd_back(stack_a, temp);
    
}

void rb(t_list **stack_b)
{
    t_list *temp;
    
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = NULL;
    ft_lstadd_back(stack_b, temp);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    ra(stack_a);
    rb(stack_b);
}