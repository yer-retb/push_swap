/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:28:00 by yer-retb          #+#    #+#             */
/*   Updated: 2022/05/30 23:28:01 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **stack, char stack_name)
{
	t_list *first;
	t_list *second;
	t_list *save;

	first = *stack;
	second = (*stack)->next;
	save = (*stack)->next->next;

	second->next = first;
	first->next = save;
	
	*stack = second;
	write(1, "s", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void ss_swap(t_list **stack_a, t_list **stack_b)
{
	if(*stack_a)
		swap(stack_a, 0);
	if(*stack_b)
		swap(stack_b, 0);
	write(1, "ss\n", 3);
}

void rotate(t_list **stack, char stack_name)
{
	t_list *head;
	t_list *save;

	head = *stack;
	save = head;
	head = head->next;
	ft_list_add_back(&head, save);

	*stack = head;
	if (stack_name)
	{
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		rotate(stack_a, 0);
	if (*stack_b)
		rotate(stack_b, 0);
	write(1, "rr\n", 3);
}
