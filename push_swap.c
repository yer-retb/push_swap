/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:28:09 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/01 00:45:12 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_list_add_back(t_list **head, t_list *node)
{
	t_list *save = *head;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	while((*head)->next)
		(*head) = (*head)->next;
	(*head)->next = node;
	node->next = NULL;
	*head = save;
}


t_list *ft_list_new(int num)
{
	t_list *head = malloc(sizeof (t_list));
	if (head ==  NULL)
		return(NULL);
	head->data = num;
	head->next = NULL;
	return(head);
}

void ft_get_id(t_list **head, int *arr, int size)
{
	while ((*head)!= NULL)
	{
		(*head)->id = get_data(arr, size, (*head)->data);
		(*head) = (*head)->next;
	}
}

void ft_node(t_list **head, char **av, int *arr)
{
	int i;
	int size;
	t_list *save;
	t_list max;

	i = 1;
	size = 0;
	while (av[i])
	{
		ft_list_add_back(head, ft_list_new(atoi(av[i++])));
		size++;
	}
	ft_if_sorted(*head);
	save = *head;
	give_id(arr, size, *head);
	//ft_get_id(head, arr, size);
	*head = save;
}

int main(int ac, char **av)
{
	t_list *head = NULL;
	t_list *stack_b = NULL;
	int   *arr;
	int i = 0;
	int j = 1;
	int x = 0;
	
	if (ac <= 1)
		exit(1);
	arr = malloc(sizeof(int) * ac - 1);
	if (!arr)
		return 0;
	while (av[++i])
		is_int(av[i]);
	while (x < ac - 1)
		arr[x++] = ft_atoi(av[j++]);
	duplicate(arr, ac - 1);
	ft_node(&head, av, arr);
	sorting(&head, &stack_b, ac - 1, arr);
	//int l = printf("%d\n",find_pos_min(&head, 0));
	// 	printf("%p\n",head);
	// 	int d = 0;
	// while (head)
	// {
	// 	printf("--> %d\n", head->id);
	// 	printf("<%d>\n", arr[d++]);
	// 	head = head->next;
	// }
	// printf("%p\n",head);
	// exit(1);

	//system("leaks push_swap");
}
