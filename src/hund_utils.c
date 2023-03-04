/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hund_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:53:56 by hsaadi            #+#    #+#             */
/*   Updated: 2022/10/04 17:07:37 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*smaller_number_is_in_range(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	int		j;
	int		i;

	first = stack->node;
	last = last_node(stack);
	j = stack->size;
	i = 0;
	while (first != NULL && ((first->index <= ((stack->len / 2) - stack->slice))
		|| (first->index >= ((stack->len / 2) + stack->slice))))
	{
		i++;
		first = first->next;
	}
	while (last != NULL && ((last->index <= ((stack->len / 2) - stack->slice))
		|| (last->index >= ((stack->len / 2) + stack->slice))))
	{
		j--;
		last = last->prev;
	}
	if (stack->len - j < i && last)
		return (last);
	else
		return (first);
}

int	number_is_in_range(t_stack *stack)
{
	t_node	*node;

	node = stack->node;
	while (node != NULL)
	{
		if ((node->index < (stack->len / 2) + stack->slice)
			&& (node->index > (stack->len / 2) - stack->slice))
			return (True);
		node = node->next;
	}
	return (False);
}

int	num_indexer(t_stack *stack, int num)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->node;
	while (node != NULL)
	{
		if (node->index == num)
			return (i);
		i++;
		node = node->next;
	}
	return (0);
}
