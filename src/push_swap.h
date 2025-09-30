/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 07:36:59 by texenber          #+#    #+#             */
/*   Updated: 2025/09/30 15:10:50 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// *** Error identifiers and error messages ****
# define ERR_MEMORY 1
# define ERR_DUPLICATE 2
# define ERR_INPUT 3
# define ERR_CHEAP 4
# define M_ERROR "Error: Memory allocation failed\n"
# define I_ERROR "Error: Invalid input\n"
# define U_ERROR "Error: Wrong error identifier\n"
# define CHEAP_ERROR "Error: Issues grabing the cheapest number\n"

# include <stdbool.h>
# include <limits.h>
# include "../include/libft/src/libft.h"
# include "../include/ft_printf/libftprintf.h"
# include <stdio.h>

typedef struct s_stack_node
{
	int					nb;
	int					index;
	int					target_index;
	int					a_cost;
	int					b_cost;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// *** Parsing Functions ***
char			**join_and_split(int ac, char **av);
void			init_stack(t_stack_node **a, char **split_args);
bool			too_many_0(const char *str);

// *** error handling ***
void			ft_error_exit(int i);
void			ft_free_args(char **split_args);
void			ft_free_stack(t_stack_node **stack);

// *** stack utils ***
t_stack_node	*find_end(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
t_stack_node	*get_cheapest_node(t_stack_node *b);
void			final_rotate(t_stack_node **a);

// *** command operations ***
void			sa(t_stack_node *a);
void			sb(t_stack_node *b);
void			ss(t_stack_node *a, t_stack_node *b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

// *** sort three ***
void			sort_three(t_stack_node **stack);

// *** sort more than 3  and sort utils***
void			sort_all(t_stack_node **a, t_stack_node **b);
void			assign_index(t_stack_node *stack);
int				assign_target_index(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b, t_stack_node *cheapest_node);
t_stack_node	*find_min_node(t_stack_node *a);

// *** execute moves ***
void			exec_move(t_stack_node **a, t_stack_node **b);

#endif //PUSH_SWAP_H