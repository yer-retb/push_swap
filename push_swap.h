/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:28:12 by yer-retb          #+#    #+#             */
/*   Updated: 2022/06/06 06:24:46 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct n_list{

	struct n_list *next;
	int data;
	int id;

} t_list;

typedef struct n_range{
	
	int min;
	int max;
	int med;

} t_range;

/* creat node , in push_swap */

t_list *ft_list_new(int num);
void ft_list_add_back(t_list **head, t_list *node);
void	 ft_node(t_list **head, char **av, int *arr);
void ft_get_id(t_list **stack_a, int *arr, int size);


/* action and moves , in ft_moves.c */

void swap(t_list **stack, char stack_name);
void ss_swap(t_list **stack_a, t_list **stack_b);
void rotate(t_list **stack, char stack_name);
void rr(t_list **stack_a, t_list **stack_b);


/* action and moves , in ft_more_move.c */

void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_b, t_list **stack_a);
void rr_rotate(t_list **stack, char stack_name);
void rrr(t_list **stack_a, t_list **stack_b);


/* check error , in check error.c */

void is_int(char *av);
void duplicate(int *arr, int num);
void ft_if_sorted(t_list *head);
int	ft_atoi(char *s);
int up_down(t_list *stack_a, int number, int size);


/* sorting , in sort.c */

void sorting(t_list **stack_a, t_list **stack_b, int num);
void ft_three(t_list **stack_a, int num);
void sort_five(t_list **stack_a, t_list **stack_b, int num);
int maximum(t_list *stack_a);
int minimum(t_list *stack_a);
int find_pos_min(t_list *stack_a, int min);
void new_id(t_list *stack_a, int size);
void push_min(t_list *stack_a, t_list *stack_b);

/* give the data , ft_id.c */

void ft_switsh(int *x, int *y);
void give_id(int *arr, int size, t_list *head);
int get_data(int *arr, int size, int data);
int stack_size(t_list *stack_a);


/* sorting big numbers , in big_sort */

void sort_stack(t_list **stack_a, t_list **stack_b);
void back_to_a(t_list **stack_a, t_list **stack_b);
int	position(int number, t_list *stack);


/*just for checking ,in ft_id, don't forget to delete them */

void print_stack(t_list *head);

#endif
