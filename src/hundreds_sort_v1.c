/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundreds_sort_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:53:56 by hsaadi            #+#    #+#             */
/*   Updated: 2022/10/04 17:04:04 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	smaller_from_a_to_b(t_stack *astack, t_stack *bstack)
{
	t_node	*node;
	int		index;

	node = astack->node;
	while (node != NULL)
	{
		astack->proch = smaller_number_is_in_range(astack)->index;
		printf("astack->proch ::==> %d \n", astack->proch);
		index = num_indexer(astack, astack->proch);
		printf("index::==> %d \n", index);
		while (node->index != astack->proch)
		{
			if (index < ((astack->size) / 2))
				rotate(&astack);
			else
				rotate_reverse(&astack);
			node = astack->node;
		}
		push_to_stack(&astack, &bstack);
		if (bstack->node->index < (astack->len / 2) && bstack->size > 1)
			rotate(&bstack);
		if (!number_is_in_range(astack) && astack->size > 1)
			astack->slice += astack->sliceflag;
		node = astack->node;
	}
}

static void	flag_decrement(t_stack *astack, t_stack *bstack)
{
	if (bstack->flag == 1)
	{
		bstack->len -= 1;
		bstack->flag = 0;
		swap_val(&astack);
	}
	else
		bstack->len--;
}

void	bigger_from_b_to_a(t_stack *astack, t_stack *bstack)
{
	t_node	*node;
	int		index;

	node = (bstack)->node;
	bstack->len = astack->len;
	while (node != NULL)
	{
		index = num_indexer(bstack, bstack->len);
		while (node->index != bstack->len)
		{
			if (node->index == bstack->len - 1)
			{
				push_to_stack(&bstack, &astack);
				bstack->flag = 1;
			}
			else if (index < (bstack->size / 2))
				rotate(&bstack);
			else
				rotate_reverse(&bstack);
			node = bstack->node;
		}
		push_to_stack(&bstack, &astack);
		flag_decrement(astack, bstack);
		node = bstack->node;
	}
}

void	sorting_hundreds(t_stack **astack, t_stack **bstack)
{
	smaller_from_a_to_b(*astack, *bstack);
	bigger_from_b_to_a(*astack, *bstack);
}
