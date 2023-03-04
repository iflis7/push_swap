/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:59:03 by hsaadi            #+#    #+#             */
/*   Updated: 2022/10/02 18:24:40 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_val(t_stack **stack)
{
	t_node	*temp;

	temp = (*stack)->node;
	if (temp != NULL && temp->next != NULL)
	{
		(*stack)->node = (*stack)->node->next;
		temp->next = NULL;
		if ((*stack)->node->next)
		{
			temp->next = (*stack)->node->next;
			(*stack)->node->next->prev = temp;
		}
		(*stack)->node->next = temp;
		temp->prev = (*stack)->node;
		(*stack)->node->prev = NULL;
		printf("s%c\n", (*stack)->name);
	}
}

void	push_to_stack(t_stack **from, t_stack **to)
{
	t_node	*temp;

	if ((*from)->node != NULL)
	{
		temp = pop(from);
		push(to, temp);
		printf("p%c\n", (*to)->name);
	}
}

void	rotate(t_stack **stack)
{
	t_node	*last;
	t_node	*head;

	if ((*stack)->size < 2)
		return ;
	last = last_node(*stack);
	head = (*stack)->node;
	last->next = (*stack)->node;
	(*stack)->node->prev = last;
	(*stack)->node = head->next;
	(*stack)->node->prev = NULL;
	head->next = NULL;
	printf("r%c\n", (*stack)->name);
}

void	rotate_reverse(t_stack **stack)
{
	t_node	*last;

	last = last_node(*stack);
	last->prev->next = NULL;
	(*stack)->node->prev = last;
	last->next = (*stack)->node;
	last->prev = NULL;
	(*stack)->node = last;
	printf("rr%c\n", (*stack)->name);
}
