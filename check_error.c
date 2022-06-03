/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:27:46 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/03 03:36:44 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	long	rsl;
	int		sn;
	int		i;

	sn = 1;
	i = 0;
	rsl = 0;
	while ((s[i] == 32) || (s[i] >= 9 && s[i] <= 13))
		i++;
	if ((s[i] == '-') || (s[i] == '+'))
	{
		if (s[i] == '-')
			sn = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		rsl = rsl * 10 + s[i] - '0';
		i++;
	}
	if (rsl > 2147483647 && rsl < -2147483648)
	{
		write(1,"Error\n",6);
		exit(1);
	}
	return (sn * rsl);
}

void is_int(char *av)
{
	int i = 0;
	while (av[i] == ' ')
		i++;
	if (!av[i])
	{
		write(1,"Error\n",6);
		exit(1);
	}
	while (av[i])
	{
		if (av[i] == '+' || av[i] == '-')
			i++;
		if (av[i] < 48 || av[i] > 57)
		{
			write(1,"Error\n",6);
			exit(1);
		}
		i++;
	}

}

void duplicate(int *arr, int num)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < num)
	{
		j = i + 1;
		while(j < num)
		{
			if (arr[i] == arr[j])
			{
				write(1,"Error\n",6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void ft_if_sorted(t_list *head)
{
	t_list *ptr;
	
	if (head->next == NULL)
		exit(1);
	ptr = head;
	while (ptr->data < ptr->next->data)
	{
		if (ptr->next->next == NULL)
			exit(1);
		ptr = ptr->next;
	}
}

int up_down(t_list *stack_a, int number, int size)
{
	t_list *head = stack_a;
	int i = -1;

	while(++i < size / 2)
	{
		if (number == head->id)
			return (1);
		head = head->next;
	}
	return (0);
}
