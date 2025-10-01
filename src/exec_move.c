/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:32:58 by texenber          #+#    #+#             */
/*   Updated: 2025/10/01 08:04:35 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_or_rotate(t_stack_node **a, t_stack_node **b,
t_stack_node *cheapest)
{
	if (cheapest->a_cost < 0)
	{
		rra(a);
		cheapest->a_cost++;
	}
	else if (cheapest->a_cost > 0)
	{
		ra(a);
		cheapest->a_cost--;
	}
	if (cheapest->b_cost < 0)
	{
		rrb(b);
		cheapest->b_cost++;
	}
	else if (cheapest->b_cost > 0)
	{
		rb(b);
		cheapest->b_cost--;
	}
}

void	exec_move(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest_node(*b);
	if (!cheapest)
		return ;
	while (cheapest->a_cost != 0 && cheapest->b_cost != 0)
	{
		if (cheapest->a_cost > 0 && cheapest->b_cost > 0)
		{
			rr(a, b);
			cheapest->a_cost--;
			cheapest->b_cost--;
		}
		else if (cheapest->a_cost < 0 && cheapest->b_cost < 0)
		{
			rrr(a, b);
			cheapest->a_cost++;
			cheapest->b_cost++;
		}
		else
			break ;
	}
	while (cheapest->a_cost != 0 || cheapest->b_cost != 0)
		rev_or_rotate(a, b, cheapest);
	pa(a, b);
}
