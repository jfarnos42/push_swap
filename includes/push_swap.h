/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:50:40 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/14 15:20:18 by jfarnos-         ###   ########.fr       */
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

/*              PARSER*/
t_list	*check_str_format(char *str);
void	check_duplicated_int(t_list *stack);
void	ft_error(char *string_error);
int		check_nonvalid_char(char *argv);
/*              CHUNKS*/
char	**create_chunk(t_list *stack_a, int chunk_size);
void	sort_chunk_array(char **chunk, int chunk_size);
int		is_in_chunk(int value, char **index, int chunk_size);
int		is_chunk_complited(t_list *stack_a, char **index, int chunk_size);
/*              SORT*/
void	sort_2(t_list **stack_a);
void	sort_3(t_list **stack_a);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	sort_complex(t_list **stack_a, t_list **stack_b);
/*              COMMANDS*/
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
/*              PUSH-SWAP*/
void	push_swap(t_list **stack_a, t_list **stack_b);
void	sort_chunks(t_list **stack_a, t_list **stack_b, char **index);
int		is_sorted(t_list *stack_a);
int		get_min_value(t_list *stack_a);
int		get_max_value(t_list *stack_a);
int		get_direction(t_list *stack, int content);
int		get_chunk_size(t_list *stack_a);
int		get_bottom_value(t_list *stack);
int		get_top_value(t_list *stack);
void	bring_to_top_a(t_list **stack, int value);
int		bring_to_top_b(t_list **stack_a, t_list **stack_b, int value,
			int previous);

// void	print_chunk(char **chunk, int chunk_size);
// void	print_list(t_list *stack);
#endif