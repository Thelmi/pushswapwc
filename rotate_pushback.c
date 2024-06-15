/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:00 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 17:53:44 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	rotate_pushback(t_Node **stacka, t_Node **stackb)
{
	t_Node	*tmp;
	int		position;
	int		i;

	position = 1;
	tmp = (*stackb);
	i = 1;
	listsize((*stacka), (*stackb));
	largestnsmallest((*stackb));
	while (tmp != NULL)
	{
		if (tmp -> data == tmp ->bmax)
			break ;
		position++;
		tmp = tmp ->next;
	}
	tmp = (*stackb);
	if (position <= (tmp ->stackb_size + 1) / 2)
	{
		while (i < position)
		{
			rotate(stackb);
			ft_printf("rb\n");
			i++;
		}
	}
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
