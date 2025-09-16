/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:56:12 by texenber          #+#    #+#             */
/*   Updated: 2025/09/16 21:36:33 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*tmp;

	if (!*src)
		return;
	tmp = *src;
	*src = (*src)->next;
	if(*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	tmp->prev = NULL;
	*dst = tmp;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}
void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
