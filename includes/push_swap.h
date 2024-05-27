/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:50:40 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/05/27 22:39:40 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./Libft/libft.h"

typedef struct s_node
{
	int		number;
	void	*next;
}			t_node;

int		check_nonvalid_char(char *argv);
t_node	*pushswap_new_node(int number);
t_node *check_str_format(char *str);
void	pushswap_add_last(t_node **stack, t_node *node);
void	ft_error(char *string_error);
void check_duplicated_int(t_node *stack);

#endif