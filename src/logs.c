/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:26:28 by hsaadi            #+#    #+#             */
/*   Updated: 2022/09/19 21:58:11 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	msg_error(char *str)
{
	write(2, &(*str), ft_strlen(str));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
