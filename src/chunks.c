/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:08:01 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/14 15:28:34 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**create_chunk(t_list *stack_a, int chunk_size)
{
	t_list	*temp;
	char	**chunk;
	int		i;

	temp = stack_a;
	chunk = (char **)malloc((chunk_size + 1) * sizeof(char *));
	if (!chunk || !temp)
		ft_error("Error1\n");
	i = 0;
	while (temp && i < chunk_size)
	{
		chunk[i] = ft_itoa(*(int *)temp->content);
		temp = temp->next;
		i++;
	}
	chunk[i] = NULL;
	return (chunk);
}

void	sort_chunk_array(char **chunk, int chunk_size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < chunk_size - 1 && chunk[i] != NULL)
	{
		j = i + 1;
		while (j < chunk_size && chunk[j] != NULL)
		{
			if (ft_atoi(chunk[j]) < ft_atoi(chunk[i]))
			{
				temp = chunk[i];
				chunk[i] = chunk[j];
				chunk[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	is_in_chunk(int value, char **index, int chunk_size)
{
	int	i;

	i = 0;
	while (index[i] && i < chunk_size)
	{
		if (value == ft_atoi(index[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	is_chunk_complited(t_list *stack_a, char **index, int chunk_size)
{
	t_list	*temp;
	int		value;
	int		i;

	temp = stack_a;
	if (!temp)
		return (TRUE);
	i = 0;
	while (i < chunk_size)
	{
		while (temp)
		{
			value = *(int *)temp->content;
			if (ft_atoi(index[i]) == value)
				return (FALSE);
			temp = temp->next;
		}
		temp = stack_a;
		i++;
	}
	return (TRUE);
}
