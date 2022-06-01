/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:27:57 by yer-retb          #+#    #+#             */
/*   Updated: 2022/05/30 23:27:58 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list *save;

	if (!*stack_a)
		return ;
	if (!*stack_b)
	{
		(*stack_b) = *stack_a;
		(*stack_a) = (*stack_a)->next;	
		(*stack_b)->next = NULL;
		write(1, "pb\n", 3);
		return ;
	}
	save = *stack_b;
	(*stack_b) = *stack_a;
	(*stack_a) = (*stack_a)->next;
	(*stack_b)->next = save;
	write(1, "pb\n", 3);
}

void pa(t_list **stack_b, t_list **stack_a)
{
	t_list *save;

	if (!*stack_a)
		return ;
	if (!*stack_b)
	{
		(*stack_b) = *stack_a;
		(*stack_a) = (*stack_a)->next;	
		(*stack_b)->next = NULL;
		write(1, "pa\n", 3);
		return ;
	}
	save = *stack_b;
	(*stack_b) = *stack_a;
	(*stack_a) = (*stack_a)->next;
	(*stack_b)->next = save;
	write(1, "pa\n", 3);
}


void rr_rotate(t_list **stack, char stack_name)
{
	t_list *head;
	t_list *save;
	t_list *ptr;

	head = *stack;
	save = head;
	ptr = head;
	while (save->next->next != NULL)
	{
		save = save->next;
	}
	head = save->next;
	save->next = NULL;
	head->next = ptr;
	*stack = head;

	if (stack_name)
	{
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		rr_rotate(stack_a, 0);
	if (*stack_b)
		rr_rotate(stack_b, 0);
	write(1, "rrr\n", 4);
}