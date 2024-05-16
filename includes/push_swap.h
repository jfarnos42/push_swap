/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:50:40 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/05/16 20:50:36 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int		number;
	void	*next;
}			t_node;

typedef struct s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
}			t_stacks;

int			check_nonvalid_char(char *argv);
int			check_duplicated_int(char **split);
void		init_stacks(t_stacks **stacks);
void		pushswap_add_back(t_node **stack_a, t_node *node);
t_node		*pushswap_new_node(int number);
t_stacks	*args_to_stack(char *argv);

#endif