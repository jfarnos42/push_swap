/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:59:45 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/04/23 19:22:59 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void init_stacks(t_stacks **stacks)
{
	*stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (*stacks == NULL)
	{
		write(1, "INIT_STACKS: Memory allocation failed\n", 38);
		exit(EXIT_FAILURE);
	}
	(*stacks)->stack_a = NULL;
	(*stacks)->stack_b = NULL;
}

char *argument_checker(char **argv)
{
	char *strArguments;
	int i;

	i = 0;
	while(argv[++i] != NULL)
	{
		strArguments = ft_strjoin(strArguments, argv[i]);
	}
	strArguments = ft_split(strArguments, ' ');
	return (strArguments);
}

void print_stack(t_list *stack)
{
	while (stack != NULL)
	{
		printf("%s ", (char *)stack->content);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_stacks	*stacks;
	t_list		*node;
	
	if (argc < 2)
	{
		write(1, "Not enough Arguments\n", 21);
		return (1);
	}
	init_stacks(&stacks);
	i = 0;
	while(argv[++i] != NULL)
	{
		node = ft_lstnew(argv[i]);
		if (node == NULL)
		{
			write(1, "Memory allocation failed\n", 24);
			return (1);	
		}
		ft_lstadd_back(&stacks->stack_a, node);
	}
	print_stack(stacks->stack_a);
	return (0);
} 
