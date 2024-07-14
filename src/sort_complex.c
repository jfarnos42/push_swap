/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:00:56 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/14 15:17:33 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_chunk(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	char	**index;
	int		top_a;
	int		i;

	index = create_chunk(*stack_a, ft_lstsize(*stack_a));
	sort_chunk_array(index, ft_argc(index));
	i = 0;
	while (!is_chunk_complited(*stack_a, index, chunk_size) && index[i])
	{
		top_a = get_top_value(*stack_a);
		if (is_in_chunk(top_a, index, chunk_size) == TRUE)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	ft_freematrix(index, ft_argc(index));
}

void	merge_chunks(t_list **stack_a, t_list **stack_b, char **index)
{
	int	target;
	int	shortcut;
	int	i;

	i = ft_argc(index) - 1;
	while (*stack_b)
	{
		target = ft_atoi(index[i]);
		if (i == 0)
			shortcut = bring_to_top_b(stack_a, stack_b, target, target);
		else
			shortcut = bring_to_top_b(stack_a, stack_b, target, ft_atoi(index[i
						- 1]));
		pa(stack_a, stack_b);
		if (shortcut == 1)
			sa(*stack_a);
		i--;
		i -= shortcut;
	}
}

void	sort_complex(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	char	**index;
	int		chunk_size;

	chunk_size = ft_lstsize(*stack_a) / get_chunk_size(*stack_a);
	index = create_chunk(*stack_a, ft_lstsize(*stack_a));
	temp = *stack_a;
	if (!index && !temp)
		ft_error("Error\n");
	sort_chunk_array(index, ft_argc(index));
	if (!is_sorted(*stack_a) && !(*stack_b))
	{
		while (ft_lstsize(*stack_a))
			sort_chunk(stack_a, stack_b, chunk_size);
		merge_chunks(stack_a, stack_b, index);
	}
	ft_freematrix(index, ft_argc(index));
	ft_lstclear(stack_a, &free);
}
