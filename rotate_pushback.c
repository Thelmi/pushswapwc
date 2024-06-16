
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhelmy <mrhelmy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:00 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/16 02:17:42 by mrhelmy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int locate_max(t_Node *stackB)
{
	int position;
	t_Node *tmp;
	
	tmp = stackB;
	position = 1;
	while (tmp != NULL)
	{
		if (tmp -> data == tmp ->bmax)
			break ;
		position++;
		tmp = tmp ->next;
	}
	return (position);
}

static void rotate_max(t_Node **stackb, int position)
{
	int i;

	i = 1;
	while (i < position)
	{
		rotate(stackb);
		ft_printf("rb\n");
		i++;
	}
}

void	rotate_pushback(t_Node **stacka, t_Node **stackb)
{
	t_Node	*tmp;
	int		position;

	position = 1;
	tmp = (*stackb);

	listsize((*stacka), (*stackb));
	largestnsmallest((*stackb));
	position = locate_max(*stackb);
	if (position <= (tmp ->stackb_size + 1) / 2)
		rotate_max(stackb, position);
	else
	{
		while (position <= tmp ->stackb_size)
		{
			reverse_rotate(stackb);
			ft_printf("rrb\n");
			position++;
		}
	}
}
