/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:10:48 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/19 22:17:07 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// void push_swap(t_list (*stack_a), t_list *stack_b)
// {
//     //  it's show time
    
    
//     //  *rie en japones*
// }

void sort_5(t_list **stack_a, t_list **stack_b)
{
    sort_3(stack_a);
    while ((*stack_b) && is_sorted((*stack_a)))
    {
        if (*(int *)(*stack_b)->content < *(int *)(*stack_a)->content)
            pa(stack_a, stack_b);
        ra(stack_a);
    }
}

void sort_3(t_list **stack_a)
{
    if (!(*stack_a) || !(*stack_a)->content || is_sorted((*stack_a)))
        return ;
    
    if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content && *(int *)(*stack_a)->content < *(int *)(*stack_a)->next->next->content)
        sa((*stack_a));
    else if (*(int *)(*stack_a)->content < *(int *)(*stack_a)->next->content && *(int *)(*stack_a)->next->content > *(int *)(*stack_a)->next->next->content)
        rra(stack_a);
    else if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->next->content && *(int *)(*stack_a)->next->content < *(int *)(*stack_a)->next->next->content)
        ra(stack_a);
    else if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content && *(int *)(*stack_a)->next->content > *(int *)(*stack_a)->next->next->content)
    {
        sa((*stack_a));
        rra(stack_a);
    }
    else if (*(int *)(*stack_a)->content < *(int *)(*stack_a)->next->content && *(int *)(*stack_a)->content > *(int *)(*stack_a)->next->next->content)
    {
        sa((*stack_a));
        ra(stack_a);
    }
}

int is_sorted(t_list (*stack_a))
{
    t_list *head;
    
    head = stack_a;
    if (!head || !head->content)
        return (FALSE);   
    while (head->next != NULL)
    {
        if (*(int *)head->content > *(int *)head->next->content)
            return (FALSE);
        head = head->next;
    }
    return (TRUE);
}

