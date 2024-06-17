/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:30:13 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/06/13 21:45:28 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_nonvalid_char(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' && argv[i + 1] && ft_isdigit(argv[i + 1]) && (i == 0 || argv[i - 1] == ' '))
			i++;
		else if (ft_isdigit(argv[i]))
			i++;
		else if (argv[i] == ' ')
			i++;
		else
			ft_error("Error\n");
	}
	return (0);
}

t_list *check_str_format(char *str)
{
	t_list *stack;
	t_list *aux;
	char **split;
	long *value;
	int i;
	
	if(!str)
		return(NULL);
	i = 0;
	stack = NULL;
	split = ft_split(str, ' ');
	while (split[i])
	{
		if (check_nonvalid_char(split[i]) == 1)
			return(ft_freematrix(split, i), NULL);
		value = ft_calloc(1, sizeof(long *));
		*value = ft_atol(split[i]);
		aux = ft_lstnew((void *)value);
		ft_lstadd_back(&stack, aux);
		if(!stack)
			return(ft_freematrix(split, i), NULL);
		i++;
	}
	aux = NULL;
	return (ft_freematrix(split, i), stack);
}
