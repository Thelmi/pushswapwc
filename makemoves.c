/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:59:17 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 17:53:44 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	makemoves(t_Node **stacka, t_Node **stackb)
{
	int	move_counta;
	int	move_countb;
	int	move_count;
	int	move_rcounta;
	int	move_rcountb;
	int	move_rcount;

	move_counta = (*stacka)-> positiona - 1;
	move_countb = (*stackb)-> positionb;
	move_count = 0;
	if (move_counta > move_countb)
		move_count = move_counta - move_countb;
	else
		move_count = move_countb - move_counta;
	move_rcounta = (*stacka)-> stacka_size + 1 - (*stacka)-> positiona;
	move_rcountb = (*stackb)-> stackb_size - (*stackb)-> positionb;
	move_rcount = 0;
	if (move_rcounta > move_rcountb)
		move_rcount = move_rcounta - move_rcountb;
	else
		move_rcount = move_rcountb - move_rcounta;
	if ((*stackb)->cheapest_cost != 1)
	{
		if ((*stacka)-> positiona <= ((*stacka)->stacka_size + 1) / 2
			&& (*stackb)-> positionb <= (*stackb)-> stackb_size / 2)
		{
			if (((*stacka)-> positiona) > 1 && ((*stacka)-> positiona - 1)
				>= (*stackb)-> positionb && ((*stacka)-> positiona != 2
					|| (*stackb)-> positionb != 2))
			{
				while (move_countb > 0)
				{
					if ((*stackb)-> positionb == 1
						&& (*stacka)->target > (*stackb)->first
						&& (*stackb)->target < (*stackb)->last)
					{
						move_count++;
						break ;
					}
					double_rotate(stacka, stackb);
					ft_printf("rr\n");
					move_countb--;
				}
				while (move_count > 0)
				{
					if ((*stacka)->target == (*stacka)->data)
						break ;
					rotate(stacka);
					ft_printf("ra\n");
					move_count--;
				}
			}
			else
			{
				while (((*stacka)-> positiona) > 1 && move_counta > 0)
				{
					double_rotate(stacka, stackb);
					ft_printf("rr\n");
					move_counta--;
				}
				while (move_count > 0 && (((*stackb)-> positionb == 1
							&& (*stackb)->stackb_size == 2
							&& !((*stacka)->data > (*stackb)->first
								&& (*stacka)->data < (*stackb)->last))
						|| ((((*stackb)-> positionb != 2)
								&& ((*stackb)->stackb_size != 2))
							|| !((*stacka)-> positiona == 1
								&& (*stackb)-> positionb == 1
								&& (*stacka)->data > (*stackb)->first
								&& (*stacka)->data < (*stackb)->last))))
				{
					rotate(stackb);
					ft_printf("rb\n");
					move_count--;
				}
			}
		}
		else if ((*stackb)-> positionb > (*stackb)-> stackb_size / 2
			&& (*stacka)-> positiona <= ((*stacka)->stacka_size + 1) / 2)
		{
			while ((*stacka)-> positiona > 1 && move_counta > 0)
			{
				rotate(stacka);
				ft_printf("ra\n");
				move_counta--;
			}
			while (move_rcountb > 0)
			{
				reverse_rotate(stackb);
				ft_printf("rrb\n");
				move_rcountb--;
			}
		}
		else if ((*stackb)-> positionb <= (*stackb)-> stackb_size / 2
			&& (*stacka)-> positiona > ((*stacka)->stacka_size + 1) / 2)
		{
			while ((*stacka)-> positiona > 1 && move_rcounta > 0)
			{
				reverse_rotate(stacka);
				ft_printf("rra\n");
				move_rcounta--;
			}
			while (move_countb > 0 && !((*stacka)->target > (*stackb)->first
					&& (*stacka)->data < (*stackb)->last))
			{
				rotate(stackb);
				ft_printf("rb\n");
				move_countb--;
			}
		}
		else if ((*stackb)-> positionb > (*stackb)-> stackb_size / 2
			&& (*stacka)-> positiona > ((*stacka)->stacka_size + 1) / 2)
		{
			if ((*stacka)-> positiona > 1 && ((*stacka)->stacka_size + 1)
				- (*stacka)-> positiona >= (*stackb)->stackb_size
				- (*stackb)-> positionb)
			{
				while (move_rcountb > 0)
				{
					double_reverse_rotate(stacka, stackb);
					ft_printf("rrr\n");
					move_rcountb--;
				}
				while (move_rcount > 0)
				{
					reverse_rotate(stacka);
					ft_printf("rra\n");
					move_rcount--;
				}
			}
			else
			{
				while (move_rcounta > 0)
				{
					double_reverse_rotate(stacka, stackb);
					ft_printf("rrr\n");
					move_rcounta--;
				}
				while (move_rcount > 0)
				{
					reverse_rotate(stackb);
					ft_printf("rrb\n");
					move_rcount--;
				}
			}
		}
	}
	push(stacka, stackb);
	ft_printf("pb\n");
}
