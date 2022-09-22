/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:37:38 by hsaadi            #+#    #+#             */
/*   Updated: 2022/09/22 14:37:38 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_get_next_line(int fd)
{
	char	*str;
	char	*buff;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 5);
	buff = str;
	while (read(fd, buff, 1) > 0 && *buff++ != '\n')
		i++;
	if (buff > str)
	{
		buff = 0;
		return (str);
	}
	else
	{
		free(str);
		return (NULL);
	}
}

void	apply_moves(t_stack *astack, t_stack *bstack, char *move)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		push_to_stack(&bstack, &astack);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push_to_stack(&astack, &bstack);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		rotate(&astack);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rotate(&bstack);
	else if (ft_strncmp(move, "rra\n", 3) == 0)
		rotate_reverse(&astack);
	else if (ft_strncmp(move, "rrb\n", 3) == 0)
		rotate_reverse(&bstack);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		swap_val(&astack);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		swap_val(&bstack);
	else
		msg_error(ERROR);
}

void	check_result(t_stack *astack, t_stack *bstack)
{
	char	*move;

	move = ft_get_next_line(0);
	while (move)
	{
		apply_moves(astack, bstack, move);
		move = ft_get_next_line(0);
	}
	if (bstack->size == 0 && already_sorted(&astack))
		printf("OK\n");
	else
		printf("KO\n");
	free(move);
}

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
		nums = &argv[1];
	store_in_stack(&astack, &bstack, nums, argc);
	check_result(astack, bstack);
	free_list(astack);
	free_list(bstack);
}
