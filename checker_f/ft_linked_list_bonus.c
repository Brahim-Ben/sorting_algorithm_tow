/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:36:59 by bbenaali          #+#    #+#             */
/*   Updated: 2025/01/23 10:26:13 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lstnew(int content)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->index = -1;
	head->data = content;
	head->next = NULL;
	return (head);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cureet;

	if (!lst)
		return (NULL);
	cureet = lst;
	while (cureet->next != NULL)
		cureet = cureet->next;
	return (cureet);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	count;
	t_list	*cureet;

	count = 0;
	if (!lst)
		return (0);
	cureet = lst;
	while (cureet != NULL)
	{
		count++;
		cureet = cureet->next;
	}
	return (count);
}

void	handle_sorting(t_list **head_a, t_list **head_b, t_list2 **bb)
{
	if (!ft_read_in(bb))
	{
		write(1, "Error\n", 6);
		ft_clear_list_two(bb);
		exit(1);
	}
	else
		ft_algo_with_number(head_a, head_b, bb);
	if (*head_b != NULL)
	{
		ft_clear(head_b);
		write(1, "KO\n", 3);
	}
	else if (ft_check_sorting_nb(*head_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
// void	put_in_node(int *b, int c)
// {
// 	t_list	*head_a;
// 	t_list	*head_b;
// 	t_list2	*bb;
// 	t_list	*new;
// 	int		l;

// 	head_a = NULL;
// 	head_b = NULL;
// 	bb = NULL;
// 	l = 0;
// 	while (l++ < c)
// 	{
// 		new = ft_lstnew(*b);
// 		ft_lstadd_back(&head_a, new);
// 		b++;
// 	}
// 	handle_sorting(&head_a, &head_b, &bb);
// 	ft_clear_list_two(&bb);
// 	ft_clear(&head_a);
// }
