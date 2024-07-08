/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:50:40 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/08 07:56:12 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include "./Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		check_nonvalid_char(char *argv);
int		is_sorted(t_list *stack_a);
int		get_min_value(t_list *stack_a);
int		get_max_value(t_list *stack_a);
int		get_direction(t_list *stack, int content);
int		get_chunk_size(t_list *stack_a);
void	sort_chunks(t_list **stack_a, t_list **stack_b);
void	ft_error(char *string_error);
void	check_duplicated_int(t_list *stack);
void	print_list(t_list *stack);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	push_swap(t_list **stack_a, t_list **stack_b);
void	sort_2(t_list **stack_a);
void	sort_3(t_list **stack_a);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	sort_complex(t_list **stack_a, t_list **stack_b);
t_list	*check_str_format(char *str);
void	print_chunk(char **chunk, int chunk_size);

#endif