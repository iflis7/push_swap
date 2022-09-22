/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:49:28 by hsaadi            #+#    #+#             */
/*   Updated: 2022/09/21 19:58:49 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rot_swap(t_stack **stack)
{
	rotate(stack);
	swap_val(stack);
}

void	sorting_three(t_stack **stack)
{
	t_node	*last;
	t_node	*head;

	head = (*stack)->node;
	last = last_node(*stack);
	if (head->val < last->prev->val && last->prev->val > last->val
		&& head->val > last->val)
		rotate_reverse(stack);
	else if (head->val < last->prev->val && last->prev->val > last->val
		&& head->val < last->val)
	{
		rotate_reverse(stack);
		swap_val(stack);
	}
	else if (head->val > last->prev->val && last->prev->val < last->val
		&& head->val < last->val)
		swap_val(stack);
	else if (head->val > last->prev->val && last->prev->val < last->val
		&& head->val > last->val)
		rotate(stack);
	else if (head->val > last->prev->val && last->prev->val > last->val
		&& head->val > last->val)
		rot_swap(stack);
}
