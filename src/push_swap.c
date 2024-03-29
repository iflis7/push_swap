/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:07:31 by hsaadi            #+#    #+#             */
/*   Updated: 2022/10/04 17:06:49 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*astack;
	t_stack	*bstack;
	char	**nums;

	if (argc < 2)
		exit(0);
	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	if (argc > 2)
	{
		check_shit(argv[2]);
		nums = &argv[1];
	}
	store_in_stack(&astack, &bstack, nums, argc);
	print_stack(astack);
	if (already_sorted(&astack))
		exit(0);
	if (astack->size == 3)
		sorting_three(&astack);
	else if (astack->size <= 5)
		sorting_five(&astack, &bstack);
	else
		sorting_hundreds(&astack, &bstack);
	print_stack(bstack);
	free_list(astack);
	free_list(bstack);
}
