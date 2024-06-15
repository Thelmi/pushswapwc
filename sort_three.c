/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:07:29 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 16:30:23 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	sort_three(t_Node **stackA)
{
	if ((*stackA)->data > (*stackA)-> next -> data
		&& (*stackA)-> next -> data > (*stackA)-> next -> next -> data)
	{
		rotate(stackA);
		printf("ra\n");
		swap(*stackA);
		printf("sa\n");
	}
	else if ((*stackA)-> data > (*stackA)-> next -> data
		&& (*stackA)-> next -> data < (*stackA)-> next -> next -> data
		&& (*stackA)-> data > (*stackA)-> next -> next -> data)
	{
		rotate(stackA);
		printf("ra\n");
	}
	else if ((*stackA)->data < (*stackA)-> next -> data
		&& (*stackA)-> next -> data > (*stackA)-> next -> next -> data
		&& (*stackA)-> data > (*stackA)-> next -> next -> data)
	{
		reverse_rotate(stackA);
		printf("rr\n");
	}
	else if ((*stackA)->data > (*stackA)-> next -> data
		&& (*stackA)-> next -> data < (*stackA)-> next -> next -> data)
	{
		swap(*stackA);
		printf("sa\n");
	}
	else
	{
		swap(*stackA);
		printf("sa\n");
		rotate(stackA);
		printf("ra\n");
	}
}
