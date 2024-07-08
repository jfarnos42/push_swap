/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_node_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:04:30 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/07/08 02:11:03 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_node(t_list **lst, int value)
{
	t_list	*head;
	t_list	*runner;
	t_list	*target;

	head = *lst;
	if (!head || !head->content)
		return (NULL);
	runner = head;
	while (runner && runner->next)
	{
		if (*(int *)runner->content == value)
		{
			target = runner;
			runner = runner->next;
			ft_lstdelone(target, &free);
			ft_lstadd_back(&head, runner);
			return (head);
		}
		runner = runner->next;
	}
	return (head);
}
