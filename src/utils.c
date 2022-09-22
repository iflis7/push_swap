/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:26:54 by hsaadi            #+#    #+#             */
/*   Updated: 2022/09/22 09:24:24 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fru(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_list(t_stack *stack)
{
	t_node	*tmp;

	while (stack->node != NULL)
	{
		tmp = stack->node;
		stack->node = stack->node->next;
		free(tmp);
	}
	free(stack);
}

int	ints_count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	indexing(int number, char **args)
{
	int	i;
	int	index;

	index = 1;
	i = 0;
	while (args[i])
	{
		if (number > ft_atoi(args[i]))
			index++;
		i++;
	}
	return (index);
}

void	clear_list(t_stack **stack)
{
	t_node	*temp;

	temp = (*stack)->node;
	while (temp != NULL)
	{
		pop(stack);
		temp = temp->next;
	}
}
