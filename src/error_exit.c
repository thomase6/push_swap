/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:35:30 by texenber          #+#    #+#             */
/*   Updated: 2025/09/30 09:26:43 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->nb = 0;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_free_args(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	ft_error_exit(int i)
{
	if (i == ERR_MEMORY)
		ft_printf(M_ERROR);
	else if (i == ERR_INPUT)
		ft_printf(I_ERROR);
	else if (i == ERR_CHEAP)
		ft_printf(CHEAP_ERROR);
	else
		ft_printf(U_ERROR);
	exit(EXIT_FAILURE);
}
