/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:27:36 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/03 02:33:52 by yer-retb         ###   ########.fr       */
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

int minimum(t_list *stack_a)
{
	t_list *head = stack_a;
	t_list *min = stack_a;
	
	while (head != NULL)
	{
		if (min->id > head->id)
			min->id = head->id;
		head = head->next;
	}
	return (min->id);
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

int maximum(t_list *stack_a)
{
	t_list *head = stack_a;
	t_list *max = stack_a;
	
	while (head != NULL)
	{
		if (max->id < head->id)
			max->id = head->id;
		head = head->next;
	}
	return (max->id);
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

void sort_four(t_list **stack_a, t_list **stack_b, int num, int f)
{
	t_list *head = *stack_a;

	if (num == 4)
		f = 0;
	while (stack_size(head) > 3)
	{
		if (up_down(head, f, stack_size(head)))
		{
			if(head->id == f)
			{
				pb(&head, stack_b);
				break ;
			}
			rotate(&head, 'a');
		}
		else
		{
			if(head->id == f)
			{
				pb(&head, stack_b);
				break ;
			}
			rr_rotate(&head, 'a');
		}
	}
	ft_three(&head, num);
	pa(&head, stack_b);
	pa(&head, stack_b);
}

void sort_five(t_list **stack_a, t_list **stack_b, int num, int *arr)
{
	t_list *head = *stack_a;
	t_list *save = *stack_a;
	
	while (stack_size(head) > 3)
	{
		if (up_down(head, 0, stack_size(head)))
		{
			if(head->id == 0)
			{
				pb(&head, stack_b);
				break ;
			}
			rotate(&head, 'a');
		}
		else
		{
			if(head->id == 0)
			{
				pb(&head, stack_b);
				break ;
			}
			rr_rotate(&head, 'a');
		}
	}
	sort_four(&head, stack_b, 5, 1);
}

void sorting(t_list **stack_a, t_list **stack_b, int num, int *arr)
{

	t_list *head = *stack_a;
	
	if (num <= 3)
		ft_three(&head, num);
	if (num	== 4)
		sort_four(stack_a, stack_b, num, 0);
	if (num == 5)
		sort_five(stack_a, stack_b, num, arr);
	else
		sort_stack(stack_a, stack_b, arr);
}
