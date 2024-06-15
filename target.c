/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:55:29 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 17:38:34 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	target(t_Node *stacka, t_Node *stackb)
{
	t_Node	*tmpa;
	t_Node	*tmpb;
	int		cheapest_cost;
	int		positiona;
	int		positionb;
	int		cost;

	tmpa = stacka;
	tmpb = stackb;
	cheapest_cost = INT_MAX;
	positiona = 0;
	positionb = 1;
	cost = 0;
	listsize((stacka), (stackb));
	largestnsmallest((stackb));
	firstnlast(stackb);
	while (tmpa != NULL)
	{
		positiona++;
		tmpb = stackb;
		positionb = 1;
		while (tmpb != NULL)
		{
			if ((tmpb->next != NULL && (tmpa->data < tmpb->data
						&& tmpa->data > tmpb->next->data))
				|| (tmpb->data == tmpb->bmin && (tmpa->data > tmpb->bmax
						|| tmpa->data < tmpb->bmin))
				|| (tmpa->data > tmpb->first && tmpa->data < tmpb->last))
			{
				if (positiona <= (tmpa ->stacka_size + 1) / 2)
				{
					if (positionb <= tmpb ->stackb_size / 2)
					{
						if (positionb == 1 && stackb ->stackb_size == 2
							&& !(tmpa->data > tmpb->first
								&& tmpa->data < tmpb->last))
							cost = 2;
						else if (positionb == 2 && stackb ->stackb_size == 2)
							cost = 1;
						else if (positiona == 1 && positionb == 1
							&& tmpa->data > tmpb->first
							&& tmpa->data < tmpb->last)
							cost = 1;
						else if (positiona > positionb)
							cost = positiona;
						else
							cost = positionb + 1;
					}
					else
						cost = positiona + (tmpb ->stackb_size - positionb);
				}
				else
				{
					if (positionb <= tmpb->stackb_size / 2)
					{
						cost = (tmpa ->stacka_size + 2) - positiona + positionb;
						if (tmpa->data > tmpb->first && tmpa->data < tmpb->last)
							cost--;
					}
					else
					{
						if ((tmpa ->stacka_size + 1) - positiona
							> tmpb ->stackb_size - positionb)
							cost = (tmpa -> stacka_size + 2) - positiona;
						else
							cost = (tmpb ->stackb_size - positionb) + 1;
					}
				}
				if (cost < cheapest_cost)
				{
					cheapest_cost = cost;
					tmpa ->positiona = positiona;
					tmpb -> positionb = positionb;
					positionab(stacka, stackb, positiona, positionb);
					target_value(stacka, tmpa -> data);
					target_value(stackb, tmpa -> data);
				}
				break ;
			}
			positionb++;
			tmpb = tmpb -> next;
		}
		tmpa = tmpa -> next;
	}
	cheapest_one(stacka, cheapest_cost);
	cheapest_one(stackb, cheapest_cost);
}
