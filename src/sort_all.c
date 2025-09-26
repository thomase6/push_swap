/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:47:21 by texenber          #+#    #+#             */
/*   Updated: 2025/09/26 13:19:46 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	set_cheapest(t_stack_node *b, t_stack_node *cheapest_node)
{
	t_stack_node	*current;

	current = b;
	while (current)
	{
		if (current == cheapest_node)
			current->cheapest = true;
		current = current->next;
	}
}
static int	find_a_cost(t_stack_node *a, t_stack_node *current)
{
	int	a_cost;
	
	if (current->target_index <= stack_len(a) / 2)
		a_cost = current->target_index;
	else
		a_cost = stack_len(a) - current->target_index;
	return (a_cost);
}

static int	find_b_cost(t_stack_node *b, t_stack_node *current)
{
	int	b_cost;

	if (current->index <= stack_len(b) / 2)
		b_cost = current->index;
	else
		b_cost = stack_len(b) - current->index;
	return (b_cost);
}

static void	find_cheapest(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*cheapest_node;
	int				lowest_cost;
	int				a_cost;
	int				b_cost;

	current = b;
	cheapest_node = NULL;
	lowest_cost = INT_MAX;
	while (current)
	{
		current->cheapest = false;
		a_cost = find_a_cost(a, current);
		b_cost = find_b_cost(b, current);
		if ((a_cost + b_cost) < lowest_cost)
		{
			lowest_cost = a_cost + b_cost;
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
	while(*b)
	{
		assign_index(*a);
		assign_index(*b);
		assign_all_targets(*a,*b);
		find_cheapest(*a, *b);
		break;
	}	
}
