/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:26:13 by hsaadi            #+#    #+#             */
/*   Updated: 2022/10/02 14:52:57 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_stacks(t_stack **astack, t_stack **bstack, char **nums)
{
	*astack = ft_calloc(sizeof(t_stack), 1);
	if (!*astack)
		msg_error(ERROR);
	(*astack)->name = 'a';
	(*astack)->slice = 5;
	(*astack)->len = ints_count(nums);
	if ((*astack)->len >= 300)
		(*astack)->slice = 30;
	(*astack)->sliceflag = (*astack)->slice;
	*bstack = ft_calloc(sizeof(t_stack), 1);
	if (!*bstack)
		msg_error(ERROR);
	(*bstack)->name = 'b';
	(*bstack)->flag = 0;
}

void	just_nums(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_isnum_space(str[i]);
		max_min_check(str[i]);
		i++;
	}
}

int	no_duplicates(t_node *node, int nb)
{
	while (node != NULL)
	{
		if (node->val == nb)
			msg_error(ERROR);
		node = (*node).next;
	}
	return (True);
}

t_node	*new_val(int value, int index)
{
	t_node	*node;

	node = calloc(sizeof(t_node), 1);
	if (!node)
		msg_error(ERROR);
	node->val = value;
	node->index = index;
	node->prev = NULL;
	return (node);
}

void	store_in_stack(t_stack **astack, t_stack **bstack, char **nums,
		int argc)
{
	int	i;
	int	j;

	just_nums(nums);
	init_stacks(astack, bstack, nums);
	j = (*astack)->len;
	while (nums[--j] && j >= 0)
	{
		i = indexing(ft_atoi(nums[j]), nums);
		if (no_duplicates((*astack)->node, ft_atoi(nums[j])))
			push(astack, new_val(ft_atoi(nums[j]), i));
	}
	if (argc == 2)
		fru(nums);
}
