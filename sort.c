/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:27:36 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/06 06:24:41 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_three(t_list **stack_a, int num)
{
	t_list *head = *stack_a;
	t_list *med = (*stack_a)->next;
	t_list *last = med->next;

	if ((num == 2) && head->id > med->id)
		{
			swap(stack_a, 'a');
			exit(1);
		}
	if (head->id > med->id && last->id > head->id)
		swap(stack_a, 'a');
	else if (head->id > last->id && last->id > med->id)
		rotate(stack_a, 'a');
	else if (head->id < last->id && last->id < med->id)
	{
		rr_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	else if (head->id < med->id && last->id < head->id)
		rr_rotate(stack_a, 'a');
	else if (head->id > med->id && med->id > last->id)
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

void print_stack(t_list *head)
{
	t_list *ptr;

	ptr = head;
	printf("-----\n");
	while (head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
	printf("-----\n");
}

int minimum(t_list *stack)
{
	t_list *head = stack;
	int min;
	
	min = head->id;
	while (head != NULL)
	{
		if (min > head->id)
			min = head->id;
		head = head->next;
	}
	return (min);
}

int maximum(t_list *stack)
{
	t_list *head = stack;
	int max;
	
	max = head->id;
	if (!head)
		return (0);
	while (head != NULL)
	{
		if (max < head->id)
			max = head->id;
		head = head->next;
	}
	return (max);
}

int find_pos_min(t_list *stack_a, int min)
{
	t_list *new;
	int	count;

	new = stack_a;
	count = 0;
	while (new != NULL)
	{
		if (min == new->id)
			break;
		new = new->next;
		count++;
	}
	return (count);
}

void new_id(t_list *stack_a, int size)
{
	t_list *head = stack_a;
	int *tab;
	int v;
	v = 0;
	tab = malloc(sizeof(int) * size);

	while (stack_a != NULL)
	{
		tab[v] = stack_a->data;
		stack_a = stack_a->next;
		v++;
	}
	give_id(tab, size, head);
}

void sort_five(t_list **stack_a, t_list **stack_b, int num)
{
	t_list *head = *stack_a;
	int min;
	
	(*stack_a) = head;
	min = minimum(*stack_a);
	while (stack_size(*stack_a) > 3)
	{
		if (up_down((*stack_a), min, num))
		{
			while (1)
			{
				if((*stack_a)->id == min)
				{
					pb(stack_a, stack_b);
					min = minimum(*stack_a);
					break ;
				}
				rotate(stack_a, 'a');
			}
		}
		else
		{
			while (1)
			{
				if((*stack_a)->id == min)
				{
					pb(stack_a, stack_b);
					min = minimum(*stack_a);
					break ;
				}
				rr_rotate(stack_a, 'a');
			}
		}
	}
	ft_three(stack_a, num);
	back_to_a(stack_a, stack_b);
}

void sorting(t_list **stack_a, t_list **stack_b, int num)
{

	t_list *head = *stack_a;
	
	if (num <= 3)
		ft_three(&head, num);
	(*stack_a) = head;
	if (num == 4 || num == 5)
		sort_five(stack_a, stack_b, num);
	if (num > 5)
		sort_stack(stack_a, stack_b);
}
