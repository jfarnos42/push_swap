/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:12:05 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/04/25 01:20:49 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

char **process_arguments(char **argv)
{
	int i;
	char *str;
	char **array;
	
	i = 0;
	str = ft_calloc(1, ft_strlen(str) + 1);
	if (!str)
		exit(EXIT_FAILURE);
	while (argv[++i] != NULL)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
	}
	array = ft_split(str, ' ');
	if (check_nonvalid_char(str) == 1)
		exit(EXIT_FAILURE);
	while (array && *array)
	{
		printf("array: %s\n", *array++);
	}
	if (check_duplicated_char(str) == 1)
		exit(EXIT_FAILURE);
	return (array);
}

int	check_nonvalid_char(char *str)
{
	int i;
	int c;
	
	i = 0;
	c = str[i] - 48;
	printf("%i", c);
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (str[i] == ' ')
			i++;
		if (!ft_isdigit(c))
			return (1);
		i++;
	}
	return (0);
}

int check_duplicated_char(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
