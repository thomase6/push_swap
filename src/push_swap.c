/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 07:37:33 by texenber          #+#    #+#             */
/*   Updated: 2025/09/16 21:38:05 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;
// 	char			**split_args;
// 	t_stack_node	*tmp;

// 	b = NULL;
// 	a = NULL;
// 	if (ac == 1 || ac == 2 && !av[1][0])
// 		return (1);
// 	else if (ac > 1)
// 	{
// 		split_args = join_and_split(ac, av);
// 		init_stack(&a, split_args);
// 		// is the stack sorted?
// 			//check how many elements we have
// 				//sort 2 and 3
// 				//use sorting algorith for >4 
// 	}
// 	return (0);
// }
int main(int ac, char **av)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;
    char **split_args;
    t_stack_node *tmp;

    if (ac < 2)
        return 0;

    split_args = join_and_split(ac, av);
    init_stack(&a, split_args);
    ft_free_args(split_args);

    ft_printf("Stack A before pb:\n");
    tmp = a;
    while (tmp)
    {
        ft_printf("%d\n", tmp->nb);
        tmp = tmp->next;
    }

    pb(&a, &b);

    ft_printf("Stack A after pb:\n");
    tmp = a;
    while (tmp)
    {
        ft_printf("%d\n", tmp->nb);
        tmp = tmp->next;
    }

    ft_printf("Stack B after pb:\n");
    tmp = b;
    while (tmp)
    {
        ft_printf("%d\n", tmp->nb);
        tmp = tmp->next;
    }

    return 0;
}
/*
-declare pointers to two data structures/linked lists, one for stack 'a' and another for stack 'b'
	-set both pointers to NULL to avoid undefined behavior and indicate we're starting with empty stacks
-Handle input count errors. Argument count must be 2 or more, and the second input myst not be empty.
	-If input errors, return "error\n"
-Handle both cases of input, wether a variable number of command line arguments, or as a string
	-if the input numbers is a string, call ft_split() to split the substrings
- Initialize stack 'a' by appending each input number as a node to stack 'a'
	-handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or '-' '+' signs
		-if errors found, free stack 'a' and return error
	-check for each input, if it is a long integer
		- if the input is a string, convert it to a long integer.
	-append the nodes to stack 'a'
-check if stack 'a' is sorted
	- if not sorted, implement our sorting algorithm
		-check for 2 numbers
			-if so, simply swap the numbers
		-check for 3 numbers
			-if so, implement our simple 'sort three' algorithm
		-check if the stack has more than 3 numbers 
			-if so, implement our turk algorithm
*/