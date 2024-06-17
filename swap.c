/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 04:33:30 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/17 05:37:31 by jfarnos-         ###   ########.fr       */
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
}

void ss(t_list *stack_a, t_list *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

