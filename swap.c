/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 04:33:30 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/24 23:12:57 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void sa(t_list *stack_a)
{
    t_list  *aux;
    void    *swap;

    if (stack_a && stack_a->next != NULL)
    {
        aux = stack_a->next;
        swap = aux->content;
        aux->content = stack_a->content;
        stack_a->content = swap;
    }
    write(1, "sa\n", 3);
}

void sb(t_list *stack_b)
{
    t_list  *aux;
    void    *swap;

    if (stack_b && stack_b->next != NULL)
    {
        aux = stack_b->next;
        swap = aux->content;
        aux->content = stack_b->content;
        stack_b->content = swap;
    }
    write(1, "sb\n", 3);
}

void ss(t_list *stack_a, t_list *stack_b)
{
    if(stack_a && stack_a->next != NULL)
        sa(stack_a);
    if(stack_b && stack_b->next != NULL)
        sb(stack_b);
    write(1, "ss\n", 3);
}

