/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:12:05 by texenber          #+#    #+#             */
/*   Updated: 2025/09/22 13:54:41 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (first->nb < second->nb && first->nb < third->nb)
	{
		rra(stack);
		sa(*stack);
	}
	else if (first->nb > second->nb && first->nb < third->nb)
		sa(*stack);
	else if (first->nb < second->nb && first->nb > third->nb)
		rra(stack);
	else if (first->nb > second->nb && first->nb > third->nb
			&& second->nb < third->nb)
		ra(stack);	
	else if (first->nb > second->nb && second->nb > third->nb)
	{
		ra(stack);
		sa(*stack);	
	}
}
