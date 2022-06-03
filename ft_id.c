/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:27:54 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/02 04:22:01 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_switsh(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int get_data(int *arr, int size, int data)
{
	int i;
	i = 0;

	while (i < size)
	{
		if (arr[i] == data)
			return (i);
		i++;
	}
	return 0;
}

void give_id(int *arr, int size, t_list *head)
{
	t_list *save;
	int i;
	int j;

	save = head;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_switsh(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	while (save != NULL)
	{
		save->id = get_data(arr, size, save->data);
		save = save->next;
	}
}

int stack_size(t_list *stack_a)
{
	t_list *head;
	int i;
	
	head = stack_a;
	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return(i);
}
