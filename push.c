/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 04:33:19 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/17 05:58:59 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *temp;

    if (stack_b && *stack_b)
    {
        temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = NULL;
        ft_lstadd_front(stack_a, temp);
    }
}

void pb(t_list **stack_b, t_list **stack_a)
{
    t_list *temp;

    if (stack_b && *stack_b)
    {
        temp = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next = NULL;
        ft_lstadd_front(stack_b, temp);
    }
}

