/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:26:47 by hsaadi            #+#    #+#             */
/*   Updated: 2022/09/22 09:34:55 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_isnum_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-')
		{
			if (str[i] == '-' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
				msg_error(ERRINT);
			i++;
		}
		else
			msg_error(ERRINT);
	}
}

void	max_min_check(char *nums)
{
	if (ft_atol(nums) < INT_MIN || ft_atol(nums) > INT_MAX)
		msg_error(ERROR);
}

int	ft_min(int a, int b)
{
	if (a == b)
		return (a);
	else if (a < b)
		return (a);
	else
		return (b);
}

t_bool	already_sorted(t_stack **stack)
{
	t_node	*temp;

	temp = (*stack)->node;
	while (temp != NULL && temp->next != NULL && (temp->val < temp->next->val))
	{
		temp = temp->next;
		if (temp->next == NULL)
			return (True);
	}
	if ((*stack)->size == 2
		&& ((*stack)->node->val > (*stack)->node->next->val))
		swap_val(stack);
	return (False);
}
