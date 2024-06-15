/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:57:00 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 20:57:00 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	only_five(t_Node *stacka, t_Node *stackb)
{
	if (stacka -> stacka_size == 5)
	{
		sort_five(&stacka, &stackb);
		sort_five(&stacka, &stackb);
		if (stackb -> data < stackb -> next -> data)
		{
			swap(stackb);
			ft_printf("sa\n");
		}
		if (!isascending(stacka))
			sort_three(&stacka);
		push(&stackb, &stacka);
		push(&stackb, &stacka);
		ft_printf("pa\n");
		ft_printf("pa\n");
		return (0);
	}
	return (1);
}

static int	sort_small(t_Node *stacka, t_Node *stackb)
{
	if (stacka -> stacka_size == 2)
	{
		swap(stacka);
		ft_printf("sa\n");
		return (0);
	}
	if (stacka -> stacka_size == 3)
	{
		sort_three(&stacka);
		return (0);
	}
	else if (stacka -> stacka_size == 4)
	{
		sort_five(&stacka, &stackb);
		if (!isascending(stacka))
			sort_three(&stacka);
		push(&stackb, &stacka);
		ft_printf("pa\n");
		return (0);
	}
	else if (only_five(stacka, stackb) == 0)
		return (0);
	return (1);
}

void	sort_all_big(t_Node *stacka, t_Node *stackb)
{
	t_Node	*tmp;

	push(&stacka, &stackb);
	ft_printf("pa\n");
	push(&stacka, &stackb);
	ft_printf("pb\n");
	mixer(&stacka, &stackb);
	while (stackb)
	{
		push(&stackb, &stacka);
		ft_printf("pa\n");
	}
	tmp = stacka;
	while (tmp -> next != NULL)
	{
		if (tmp -> data > tmp -> next-> data)
		{
			ft_printf("alert.....................\n");
			break ;
		}
		tmp = tmp -> next;
	}
}

int	main(int ac, char **av)
{
	t_Node	*stacka;
	t_Node	*stackb;

	stacka = is_valid(ac, av);
	stackb = NULL;
	if (isascending(stacka))
		return (0);
	listsize(stacka, stackb);
	if (sort_small(stacka, stackb) == 0)
		return (0);
	sort_all_big(stacka, stackb);
}

// push(&stacka, &stackb);
	// ft_printf("pa\n");
	// push(&stacka, &stackb);
	// ft_printf("pb\n");
	// mixer(&stacka, &stackb);
	// while (stackb)
	// {
	// 	push(&stackb, &stacka);
	// 	ft_printf("pa\n");
	// }
	// tmp = stacka;
	// while (tmp -> next != NULL)
	// {
	// 	if (tmp -> data > tmp -> next-> data)
	// 	{
	// 		ft_printf("alert.....................\n");
	// 		break ;
	// 	}
	// 	tmp = tmp -> next;
	// }
// else if (stacka -> stacka_size == 5)
	// {
	// 	sort_five(&stacka, &stackb);
	// 	sort_five(&stacka, &stackb);
	// 	if (stackb -> data < stackb -> next -> data)
	// 	{
	// 		swap(stackb);
	// 		ft_printf("sa\n");
	// 	}
	// 	if (!isascending(stacka))
	// 		sort_three(&stacka);
	// 	push(&stackb, &stacka);
	// 	push(&stackb, &stacka);
	// 	ft_printf("pa\n");
	// 	ft_printf("pa\n");
	// 	return (0);
	// }
// if (stacka -> stacka_size == 2)
	// {
	// 	swap(stacka);
	// 	ft_printf("sa\n");
	// 	return (0);
	// }
	// if (stacka -> stacka_size == 3)
	// {
	// 	sort_three(&stacka);
	// 	return (0);
	// }
	// else if (stacka -> stacka_size == 4)
	// {
	// 	sort_five(&stacka, &stackb);
	// 	if (!isascending(stacka))
	// 		sort_three(&stacka);
	// 	push(&stackb, &stacka);
	// 	ft_printf("pa\n");
	// 	return (0);
	// }
	// else if (stacka -> stacka_size == 5)
	// {
	// 	sort_five(&stacka, &stackb);
	// 	sort_five(&stacka, &stackb);
	// 	if (stackb -> data < stackb -> next -> data)
	// 	{
	// 		swap(stackb);
	// 		ft_printf("sa\n");
	// 	}
	// 	if (!isascending(stacka))
	// 		sort_three(&stacka);
	// 	push(&stackb, &stacka);
	// 	push(&stackb, &stacka);
	// 	ft_printf("pa\n");
	// 	ft_printf("pa\n");
	// 	return (0);
	// }