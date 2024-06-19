/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:50:40 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/19 20:55:39 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./Libft/libft.h"

int		check_nonvalid_char(char *argv);
void	ft_error(char *string_error);
void 	check_duplicated_int(t_list *stack);
void    print_list(t_list *stack);
void    sa(t_list *stack_a);
void    sb(t_list *stack_b);
void    ss(t_list *stack_a, t_list *stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_b, t_list **stack_a);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);
t_list  *check_str_format(char *str);
void    sort_3(t_list **stack_a);
void    sort_5(t_list **stack_a, t_list **stack_b);
int     is_sorted(t_list *stack_a);

#endif