/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:53:39 by texenber          #+#    #+#             */
/*   Updated: 2025/09/12 10:12:36 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**split_args;

	i = 0;
	if (ac < 2 || ac == 2 && !av[1][0])
		return (1);
	else if (ac > 1)
	{
		split_args = join_and_split(ac, av);
	}
	while (split_args[i])
	{
		ft_printf("%s\n", split_args[i]);
		free(split_args[i]);
		i++;
	}
	free (split_args);
	return (0);
}
