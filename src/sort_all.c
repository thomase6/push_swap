/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:47:21 by texenber          #+#    #+#             */
/*   Updated: 2025/09/25 09:23:14 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//change calculate_cost back to static int
static void	calculate_cost(t_stack_node *a, t_stack_node *b, t_stack_node *current)
{
	int	a_cost;
	int	b_cost;
	
	a_cost = calculate_a_cost(a, current);
	calculate_b_cost(b, current);

	
}


static void	find_cheapest(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current = b;
	int				current_cost;
	
	while (current)
	{
		// current_cost = calculate_cost(a, b, current);
		// if (current_cost < a->cheapest)
		// 	a->cheapest = current->nb;
		current = current->next;
	}
}

static void	init_sort(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
		pb(a, b);	
}

void	sort_all(t_stack_node **a, t_stack_node **b)
{
	init_sort(a, b);
	sort_three(a);
	assign_index(*a);
	assign_index(*b);
	assign_target_index(*a, *b);
	// find_cheapest(*a, *b);	
}