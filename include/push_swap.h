/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:40:17 by hsaadi            #+#    #+#             */
/*   Updated: 2022/09/22 14:54:24 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ***** INCLUDES ***** */
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

/* ***** MACROS ***** */

# define ERROR "Error!"

/* ***** ENUMS ***** */
typedef enum e_bool
{
	False,
	True
}					t_bool;

/* ***** STRUCTS ***** */
typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				max;
	int				min;
	int				size;
	int				name;
	int				slice;
	int				sliceflag;
	int				len;
	int				flag;
	int				proch;
	struct s_node	*node;

}					t_stack;

/* ***** CHECK_ARGS.C ***** */
void				store_in_stack(t_stack **astack, t_stack **bstack,
						char **argv, int argc);

/* ***** STACK_OPS.C ***** */
void				print_stack(t_stack *stack);
void				push(t_stack **stack, t_node *new);
t_node				*pop(t_stack **stack);
t_node				*last_node(t_stack *stack);
void				print_stack_ind(t_stack *stack);

/* ***** LOGS.c ***** */
void				msg_error(char *str);

/* ***** UTILS.c ***** */
void				fru(char **str);
void				free_list(t_stack *stack);
int					indexing(int number, char **args);
int					ints_count(char **tab);

/* ***** TOOLS.c ***** */
void				ft_isnum_space(char *str);
void				max_min_check(char *nums);
int					ft_min(int a, int b);

/* ***** SORTING_SMALL.c ***** */
t_bool				already_sorted(t_stack **stack);
void				sorting_three(t_stack **stack);
void				sorting_five(t_stack **astack, t_stack **bstack);

/* ***** ALLOWED_OPS.c ***** */
void				swap_val(t_stack **stack);
void				push_to_stack(t_stack **from, t_stack **to);
void				rotate(t_stack **stack);
void				rotate_reverse(t_stack **stack);

/* ***** SORT_HUNDRENDS.c ***** */
void				sorting_hundreds(t_stack **astack, t_stack **bstack);

/* ***** SORT_HUND_V1.c ***** */
t_node				*smaller_number_is_in_range(t_stack *stack);
int					number_is_in_range(t_stack *stack);
int					num_indexer(t_stack *stack, int num);

#endif