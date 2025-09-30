/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:47:21 by texenber          #+#    #+#             */
/*   Updated: 2025/09/30 09:38:47 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_a_cost(t_stack_node *a, t_stack_node *current)
{
	int	a_cost;

	if (current->target_index <= stack_len(a) / 2)
		a_cost = current->target_index;
	else
		a_cost = current->target_index - stack_len(a);
	return (a_cost);
}

static int	find_b_cost(t_stack_node *b, t_stack_node *current)
{
	int	b_cost;

	if (current->index <= stack_len(b) / 2)
		b_cost = current->index;
	else
		b_cost = current->index - stack_len(b);
	return (b_cost);
}

static void	find_cheapest(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*cheapest_node;
	int				lowest_cost;

	current = b;
	cheapest_node = NULL;
	lowest_cost = INT_MAX;
	while (current)
	{
		current->cheapest = false;
		current->a_cost = find_a_cost(a, current);
		current->b_cost = find_b_cost(b, current);
		if (((ft_abs(current->a_cost)) + (ft_abs(current->b_cost)))
			< lowest_cost)
		{
			lowest_cost = ((ft_abs(current->a_cost))
					+ (ft_abs(current->b_cost)));
			cheapest_node = current;
		}
		current = current->next;
	}
	set_cheapest(b, cheapest_node);
}

static void	assign_all_targets(t_stack_node *a, t_stack_node *b)
{
	while (b)
	{
		b->target_index = assign_target_index(a, b);
		b = b->next;
	}
}

void	sort_all(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
		pb(a, b);
	if (!is_sorted(*a))
		sort_three(a);
	while (*b)
	{
		assign_index(*a);
		assign_index(*b);
		assign_all_targets(*a,*b);
		find_cheapest(*a, *b);
		exec_move(a, b);
	}
	final_rotate(a);
}
