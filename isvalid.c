/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:54 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/15 18:38:38 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_Node	*is_valid(int ac, char **av)
{
	int		i;
	char	**splitted;
	int		checked;
	t_Node	*head;
	t_Node	*tmp;
	t_Node	*nextnode;
	int		j;

	i = 1;
	checked = 1;
	head = NULL;
	j = 0;
	if (ac <= 1)
		exit(1);
	while (i < ac)
	{
		if (t_defence(av[i]) && isnot_term(av[i]))
		{
			if (t_strchr(av[i], ' '))
			{
				splitted = ft_split(av[i], ' ');
				if (checked)
				{
					while (splitted[j] && checked)
					{
						if (!is_integer(splitted[j]))
						{
							ft_printf("error");
							exit(0);
						}
						j++;
					}
					checked = 0;
				}
				j = 0;
				if (!head)
				{
					head = create_node(t_atoi(splitted[0]));
					tmp = head;
					j = 1;
				}
				while (splitted[j])
				{
					nextnode = create_node(t_atoi(splitted[j]));
					tmp -> next = nextnode;
					tmp = tmp -> next;
					j++;
				}
				j = 0;
				while (splitted[j])
				{
					free(splitted[j]);
					j++;
				}
				free(splitted);
				j = 0;
			}
			else
			{
				if (!head)
				{
					head = create_node(t_atoi(av[i]));
					tmp = head;
				}
				else
				{
					nextnode = create_node(t_atoi(av[i]));
					tmp -> next = nextnode;
					tmp = nextnode;
				}
			}
		}
		else
		{
			ft_printf("error\n");
			freelist(head);
			exit(1);
		}
		i++;
	}
	isdouble(head);
	return (head);
}
