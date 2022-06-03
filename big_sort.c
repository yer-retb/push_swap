/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:27:33 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/03 22:25:56 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_range *ft_range(t_list *stack_a, t_range *range)
{
	range->min = range->max + 1;
	range->max += (stack_size(stack_a) / 4) + 1;
	range->med = (range->min + range->max) / 2;
	return(range);
}

t_range *init(t_list *stack_a, t_range *range)
{
	range->min = 0;
	range->max = (stack_size(stack_a) / 4) + 1;
	range->med = (range->min + range->max) / 2;
	return(range);
}

int camera(t_list *stack_a, t_range *range)
{
	while (stack_a != NULL)
	{
		if (range->min <= stack_a->id && stack_a->id <= range->max)
			return (1);
		stack_a = stack_a->next;
	}
	return(0);
}

int update(t_list *stack_a, t_range *range)
{
	int x;
	int size;

	size = stack_size(stack_a);
	x = -1;
	while (++x < size / 2)
	{
		if (range->min <= stack_a->id && stack_a->id <= range->max)
			return (1);
		stack_a = stack_a->next;
	}
	return(0);
}

void push_b(t_list **stack_a, t_list **stack_b, t_range *range)
{

	while (1)
	{
		if (!camera(*stack_a, range))
			return ;
		else if (update(*stack_a, range))
		{
			while (1)
			{
				if (range->min <= (*stack_a)->id && (*stack_a)->id <= range->max)
				{
					if ((*stack_a)->id > range->med)
						pb(stack_a, stack_b);
					else
					{
						pb(stack_a, stack_b);
						rotate(stack_b, 'b');
					}
					break;
				}		
				rotate(stack_a, 'a');
			}
		}
		else
		{
			while (1)
			{
				if (range->min <= (*stack_a)->id && (*stack_a)->id <= range->max)
				{
					if ((*stack_a)->id > range->med)
						pb(stack_a, stack_b);
					else
					{
						pb(stack_a, stack_b);
						rotate(stack_b, 'b');
					}
					break;
				}		
				rr_rotate(stack_a, 'a');
			}
		}
	}
}

int	position(int number, t_list *stack)
{
	t_list *head = stack;
	int i = -1;
	int size;

	size = stack_size(head);
	while (++i < size / 2)
	{
		if (number == head->id)
			return(1);
		head = head->next;
	}
	return (0);
}

void back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list *head;
	int max;

	head = *stack_b;
	max = maximum(head);
	while (1)
	{
		if ((*stack_b) == NULL)
			return ;
		else if (position(max , (*stack_b)))
		{
			while (1)
			{
				if ((*stack_b)->id == max)
				{
					pa(stack_a, stack_b);
					max--;
					break;
				}
				rotate(stack_b, 'b');
			}
		}
		else
		{
			while(1)
			{
				if ((*stack_b)->id  == max)
				{
					pa(stack_a, stack_b);
					max--;
					break;
				}
				rr_rotate(stack_b, 'b');
			}
		}
	}
}

void sort_stack(t_list **stack_a, t_list **stack_b, int *arr)
{
	t_range *range;

	

	range = malloc(sizeof(t_range));
	range = init(*stack_a, range);
	while (stack_size(*stack_a) > 5)
	{
		push_b(stack_a, stack_b, range);
		range = ft_range(*stack_a, range);
	}
	new_id((*stack_a) ,stack_size(*stack_a));
	sort_five(stack_a, stack_b, stack_size(*stack_a), arr);
	back_to_a(stack_a, stack_b);
}
