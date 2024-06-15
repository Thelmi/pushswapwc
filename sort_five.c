/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:13:04 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 17:53:45 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	sort_five(t_Node **stacka, t_Node **stackb)
{
	int	positiona;

	positiona = 0;
	largestnsmallest(*stacka);
	smallest_position(*stacka);
	listsize(*stacka, *stackb);
	if ((*stacka)-> positiona <= ((*stacka)-> stacka_size + 1) / 2)
	{
		positiona = (*stacka)-> positiona;
		while ((positiona - 1) > 0)
		{
			rotate(stacka);
			ft_printf("ra\n");
			positiona--;
		}
		push(stacka, stackb);
		ft_printf("pb\n");
	}
	else
	{
		positiona = (*stacka)-> stacka_size + 1 - (*stacka)-> positiona;
		while (positiona > 0)
		{
			reverse_rotate(stacka);
			ft_printf("rra\n");
			positiona--;
		}
		push(stacka, stackb);
		ft_printf("pb\n");
	}
}
