/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_parse_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:34:18 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 17:53:44 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	freelist(t_Node *list)
{
	t_Node	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		tmp = list -> next;
		free(list);
		list = tmp;
	}
}

void	isdouble(t_Node *list)
{
	t_Node	*tmp;
	t_Node	*store;

	tmp = list -> next;
	store = list;
	while (list != NULL)
	{
		while (tmp != NULL)
		{
			if (list -> data == tmp -> data)
			{
				ft_printf("error\n");
				freelist(store);
				exit(1);
			}
			tmp = tmp -> next;
		}
		list = list ->next;
		if (list)
			tmp = list ->next;
	}
}
