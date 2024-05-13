/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:30:13 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/05/13 18:41:50 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stacks	*args_to_stack(int argc, char **argv)
{
    t_node      *node;
    t_stacks    *stacks;
	int         i;

    i = 0;
    while(++i <= argc)
    {
        node = pushswap_new_node(argv + i);
        if (node == NULL)
            exit(EXIT_FAILURE);
    }
    return(&stacks);
}

int	*check_nonvalid_char(char *argv)
{
	int i;
	
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' && ft_isdigit(argv[i + 1]))
			i++;
		else if (ft_isdigit(argv[i]))
			i++;
		else if (argv[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

void check_node_data(t_stacks *stacks)
{
    //1.Check unvalid char && is_all_digits(negative too);
    //2.Check if multiple characters in a single block
    //              && split new_node(); 
    //3.Check if number duplicated(t_stack type);
    
    
}