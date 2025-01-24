/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_for_in_put.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:23:23 by bbenaali          #+#    #+#             */
/*   Updated: 2025/01/23 10:28:51 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list2	*ft_lstnew_bonus(char *content)
{
	t_list2	*head;

	head = (t_list2 *)malloc(sizeof(t_list2));
	if (!head)
		return (NULL);
	head->data2 = content;
	head->next2 = NULL;
	return (head);
}

t_list2	*ft_lstlast_bonus(t_list2 *lst)
{
	t_list2	*cureet;

	if (!lst)
		return (NULL);
	cureet = lst;
	while (cureet->next2 != NULL)
		cureet = cureet->next2;
	return (cureet);
}

void	ft_lstadd_back_bonus(t_list2 **lst, t_list2 *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast_bonus(*lst)->next2 = new;
}

size_t	ft_lstsize_bonus(t_list2 *lst)
{
	size_t	count;
	t_list2	*cureet;

	count = 0;
	if (!lst)
		return (0);
	cureet = lst;
	while (cureet != NULL)
	{
		count++;
		cureet = cureet->next2;
	}
	return (count);
}

void	put_in_node_input(char *line, t_list2 **bb)
{
	t_list2	*new;

	new = ft_lstnew_bonus(line);
	ft_lstadd_back_bonus(bb, new);
}
