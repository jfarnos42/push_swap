/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:12:05 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/04/26 04:44:26 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_nonvalid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' && ft_isdigit(str[i + 1])))
			i++;
		else if (str[i] == ' ')
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else
			return (write(1, "ERROR: NON-VALID CHARACTER.\n", 28), 1);
	}
	return (0);
}

int	check_duplicated_int(char **split)
{
	int	i;
	int	j;
	int	number1;
	int	number2;

	i = 0;
	while (split)
	{
		j = i + 1;
		number1 = ft_atoi(split[i]);
		while (split[j])
		{
			number2 = ft_atoi(split[j]);
			if (number1 == number2)
				return (write(1, "ERROR: DUPLICATED NUMBER.\n", 26), 1);
			j++;
		}
		i++;
	}
	return (0);
}

void	pushswap_add_back(t_node **stack_a, t_node *node)
{
	t_node	*p_aux;

	p_aux = *stack_a;
	if (node)
	{
		while (p_aux->next != NULL)
			p_aux = p_aux->next;
		if (p_aux)
			p_aux = node;
		else
			p_aux->next = node;
	}
}

t_stacks	*char_to_stack(char **array)
{
	int			i;
	t_stacks	*stack;
	t_node		*node;

	i = 0;
	node = NULL;
	init_stacks(&stack);
	while (array[++i] != NULL)
	{
		node = pushswap_new_node(ft_atoi(array[i]));
		if (node == NULL)
			return ((write(1, "Memory allocation failed\n", 24), NULL));
		pushswap_add_back(&(stack->stack_a), node);
	}
	return (stack);
}

t_stacks	*process_arguments(char **argv)
{
	int			i;
	char		*str;
	char		**array;
	t_stacks	*stack;

	str = ft_calloc(1, ft_strlen(str) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (argv[++i] != NULL)
	{
		str = ft_strappend(str, argv[i]);
		str = ft_strappend(str, " ");
	}
	if (check_nonvalid_char(str) == 1)
		return (NULL);
	array = ft_split(str, ' ');
	free(str);
	if (check_duplicated_int(array) == 1)
		return (NULL);
	stack = char_to_stack(array);
	free(array);
	return (stack);
}
