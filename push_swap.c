/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:10:48 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/19 19:06:29 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

// void push_swap(t_list *stack_a, t_list *stack_b)
// {
//     //  it's show time
    
    
//     //  *rie en japones*
// }

void sort_3(t_list **stack_a)
{
    t_list *temp;

    temp = *stack_a;
    if (!temp || !temp->content || is_sorted(*stack_a))
        return ;
    
    if (temp->content > temp->next->content && temp->content < temp->next->next->content)
        sa(*stack_a);
    else if (temp->content < temp->next->content && temp->next->content > temp->next->next->content)
        rra(stack_a);
    else if (temp->content > temp->next->next->content && temp->next->content < temp->next->next->content)
        ra(stack_a);
    else if (temp->content > temp->next->content && temp->next->content > temp->next->next->content)
    {
        sa(*stack_a);
        rra(stack_a);
    }
    else if (temp->content < temp->next->content && temp->content > temp->next->next->content)
    {
        sa(*stack_a);
        ra(stack_a);
    }
    print_list(stack_a);
}

int is_sorted(t_list *stack_a)
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

