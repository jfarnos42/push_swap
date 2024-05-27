/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:30:13 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/05/27 23:27:26 by jfarnos-         ###   ########.fr       */
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
		ft_error("Non-valid character has been found.\n");
	}
	return (0);
}

t_node *check_str_format(char *str)
{
	t_node *stack;
	t_node *aux;
	char **split;
	int i;
	
	if(!str)
		return(NULL);
	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		if (check_nonvalid_char(split[i]) == 1)
			return(ft_freematrix(split, i), NULL);
		else
		{
			aux = pushswap_new_node(ft_atoi(split[i]));
			pushswap_add_last(&stack, aux);
			if(!stack)
				return(ft_freematrix(split, i), NULL);
		}
		i++;
		
	}
	return (ft_freematrix(split, i), stack);
}
