/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:02:58 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/20 15:29:20 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"


void check_size(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp2;
	
	tmp = *a;
	while(tmp)
	{
		tmp2 = *a;
		while(tmp2 != tmp->next)
		{
			if(tmp->content >= tmp2->content)
				tmp->log += 1;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}	
}

void make_list(t_stack **a)
{
	t_stack *tmp;
	
	int	i ;
	
	check_size(a);
	*a = ft_lstlast(*a);
	i = (*a)->log - 1;
	while((*a)->previous)
	{
		tmp = *a;
		while(tmp->previous)
		{
			if((*a)->log < tmp->log && tmp->log <= i)
			{
				(*a)->dis = 0;
				break;
			}
			tmp = tmp->previous;
		}
		if((*a)->dis == 1)
			i = (*a)->log - 1;
		tmp = (*a);
		while(tmp->previous)
		{	
			if((*a)->dis == 1 && (*a)->content < tmp->content && (*a)->log >= tmp->log )
				(tmp)->dis = 0;
			tmp = tmp->previous;
		}
		(*a) =(*a)->previous;
	}
	*a = ft_lstfirst(*a);
}

