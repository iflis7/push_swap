/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 05:04:32 by hsaadi            #+#    #+#             */
/*   Updated: 2022/09/26 12:58:26 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	first_case(t_stack **astack, t_stack **bstack)
{
	rotate_reverse(astack);
	push_to_stack(bstack, astack);
	rotate(astack);
	rotate(astack);
}

static void	second_case(t_stack **astack, t_stack **bstack)
{
	rotate(astack);
	push_to_stack(bstack, astack);
	swap_val(astack);
	rotate_reverse(astack);
}

static void	algo_five(t_stack **astack, t_stack **bstack)
{
	t_node	*last_a;
	t_node	*bhead;

	bhead = (*bstack)->node;
	last_a = last_node(*astack);
	if (bhead->val < (*astack)->node->val)
		push_to_stack(bstack, astack);
	else if (bhead->val > last_a->val)
	{
		push_to_stack(bstack, astack);
		rotate(astack);
	}
	else if (bhead->val > (*astack)->node->val
		&& bhead->val < (*astack)->node->next->val)
	{
		push_to_stack(bstack, astack);
		swap_val(astack);
	}
	else if (bhead->val < last_a->val && bhead->val > last_a->prev->val)
		first_case(astack, bstack);
	else if (bhead->val < last_node(*astack)->prev->val
		&& bhead->val > (*astack)->node->next->val)
		second_case(astack, bstack);
}

void	sorting_five(t_stack **astack, t_stack **bstack)
{
	int	keep;

	keep = (*astack)->size;
	while ((*astack)->size > 3)
		push_to_stack(astack, bstack);
	if ((*astack)->size == 3)
		sorting_three(astack);
	while ((*astack)->size < keep)
		algo_five(astack, bstack);
}
