/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 07:37:33 by texenber          #+#    #+#             */
/*   Updated: 2025/10/01 08:47:59 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_args;
	int				a_count;

	b = NULL;
	a = NULL;
	split_args = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	split_args = join_and_split(ac, av);
	init_stack(&a, split_args);
	if (!is_sorted(a))
	{
		a_count = stack_len(a);
		if (a_count == 2)
			sa(a);
		else if (a_count == 3)
			sort_three(&a);
		else if (a_count > 3)
			sort_all(&a, &b);
	}
	ft_free_args(split_args, &a);
	return (0);
}
