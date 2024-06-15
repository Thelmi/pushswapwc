/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:36 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/14 14:09:36 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	swap(t_Node *list)
{
	int	swp;

	swp = list -> data;
	list -> data = list -> next -> data;
	list -> next -> data = swp;
}

void	double_swap(t_Node *listA, t_Node *listB)
{
	swap(listA);
	swap(listB);
	printf("ss\n");
}

void	push(t_Node **listA, t_Node **listB)
{
	t_Node	*tmp;

	tmp = *listA;
	*listA = (*listA)-> next;
	tmp -> next = *listB;
	*listB = tmp;
}
