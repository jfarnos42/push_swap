/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:10:48 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/24 22:58:49 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void push_swap(t_list **stack_a, t_list **stack_b)
{
    int list_size;

    if (!stack_a || !stack_b)
        ft_error("Error");

    list_size = ft_lstsize(*stack_a);
    
    if (list_size == 2)
        sort_2(stack_a);
    else if (list_size == 3)
        sort_3(stack_a);
    else if(list_size <= 5 && list_size > 3)
        sort_5(stack_a, stack_b);
    else
        //sort_complex(stack_a, stack_b);
        printf("sort_complex\n");
}

void sort_5(t_list **stack_a, t_list **stack_b)
{
    while(ft_lstsize(*stack_a) > 3)
    {
        while(do_you_know_the_way(*stack_a, get_min_value(*stack_a)) != 0)
        {
            if (do_you_know_the_way(*stack_a, get_min_value(*stack_a)) > 0)
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

void sort_3(t_list **stack_a)
{
    if (!(*stack_a) || !(*stack_a)->content || is_sorted((*stack_a)))
        return;
    
    while (!is_sorted(*stack_a))
    {
        if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content && *(int *)(*stack_a)->content < *(int *)(*stack_a)->next->next->content)
            sa((*stack_a));
        else if (*(int *)(*stack_a)->content < *(int *)(*stack_a)->next->content&& *(int *)(*stack_a)->next->content > *(int *)(*stack_a)->next->next->content)
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
}

void sort_2(t_list **stack_a)
{
    t_list *temp;

    temp = *stack_a;
    if (!temp || is_sorted(*stack_a))
        return ;
    ra(stack_a);    
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

int get_min_value(t_list *stack_a)
{
    t_list *temp;
    int     min_value;

    temp = stack_a;
    if (!temp)
        ft_error("Error\n");
    min_value = *(int *)temp->content;
    while(temp && temp->next)
    {
        if (min_value > *(int *)temp->next->content)
            min_value = *(int *)temp->next->content;
        temp = temp->next;
    }
    return (min_value);
}

int do_you_know_the_way(t_list *stack, int content)
{
    t_list *temp;
    int list_size;
    int i;

    i = 0;
    temp = stack;
    if(!stack || !content)
        ft_error("Error\n");
    while(*(int *)temp->content != content)
    {
        i++;
        temp = temp->next;
    }
    list_size = ft_lstsize(stack);
    if (i > ( list_size / 2))
        return (i - list_size);
    return (i);
}

