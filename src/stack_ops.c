/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:26:40 by hsaadi            #+#    #+#             */
/*   Updated: 2022/09/22 20:16:28 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->node;
	printf("Stack-%c: \n", stack->name);
	while (temp != NULL)
	{
		printf("%d -> ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void	print_stack_ind(t_stack *stack)
{
	t_node	*temp;

	temp = stack->node;
	printf("Stack-%c:  \n", stack->name);
	while (temp != NULL)
	{
		printf("|%d| -> |%d| \n", temp->index, temp->val);
		temp = temp->next;
	}
	printf("\n");
}

void	push(t_stack **stack, t_node *new)
{
	if ((*stack)->node == NULL && new)
	{
		(*stack)->node = new;
		(*stack)->node->next = NULL;
		(*stack)->node->prev = NULL;
	}
	else if ((*stack)->node != NULL && new)
	{
		new->next = (*stack)->node;
		(*stack)->node->prev = new;
		(*stack)->node = new;
		(*stack)->node->prev = NULL;
	}
	(*stack)->node->prev = NULL;
	(*stack)->size++;
}

t_node	*pop(t_stack **stack)
{
	t_node	*res;

	res = NULL;
	if ((*stack)->node != NULL)
	{
		res = (*stack)->node;
		(*stack)->node = (*stack)->node->next;
		(*stack)->size--;
		if ((*stack)->node != NULL)
			(*stack)->node->prev = NULL;
	}
	return (res);
}

t_node	*last_node(t_stack *stack)
{
	t_node	*temp;

	temp = stack->node;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
