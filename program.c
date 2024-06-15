/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:39 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/14 12:55:39 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	main(int ac, char **av)
{
	t_Node	*stacka;
	t_Node	*stackb;
	t_Node	*tmp;

	stacka = is_valid(ac, av);
	stackb = NULL;
	if (isascending(stacka))
		return (0);
	listsize(stacka, stackb);
	if (stacka -> stacka_size == 2)
	{
		swap(stacka);
		printf("sa\n");
		printlist(stacka);
		return (0);
	}
	if (stacka -> stacka_size == 3)
	{
		sort_three(&stacka);
		printlist(stacka);
		return (0);
	}
	else if (stacka -> stacka_size == 4)
	{
		sort_five(&stacka, &stackb);
		if (!isascending(stacka))
			sort_three(&stacka);
		push(&stackb, &stacka);
		printf("pa\n");
		printlist(stacka);
		return (0);
	}
	else if (stacka -> stacka_size == 5)
	{
		sort_five(&stacka, &stackb);
		sort_five(&stacka, &stackb);
		if (stackb -> data < stackb -> next -> data)
		{
			swap(stackb);
			printf("sa\n");
		}
		if (!isascending(stacka))
			sort_three(&stacka);
		push(&stackb, &stacka);
		push(&stackb, &stacka);
		printf("pa\n");
		printf("pa\n");
		printlist(stacka);
		return (0);
	}
	push(&stacka, &stackb);
	printf("pa\n");
	push(&stacka, &stackb);
	printf("pb\n");
	mixer(&stacka, &stackb);
	while (stackb)
	{
		push(&stackb, &stacka);
		printf("pa\n");
	}
	tmp = stacka;
	while (tmp -> next != NULL)
	{
		if (tmp -> data > tmp -> next-> data)
		{
			printf("alert.....................\n");
			break ;
		}
		tmp = tmp -> next;
	}
}
