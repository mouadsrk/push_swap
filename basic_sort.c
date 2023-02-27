/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:28:32 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 19:38:01 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	int	i1;
	int	i2;
	int	i3;

	if (!*a)
		return ;
	i1 = (*a)->content;
	i2 = (*a)->next->content;
	i3 = (*a)->next->next->content;
	if ((i1 > i2 && i1 < i3) || (i1 > i2 && i2 > i3) || (i1 < i3 && i3 < i2))
		sa(a,"sa\n", 1);
	i1 = (*a)->content;
	i2 = (*a)->next->content;
	i3 = (*a)->next->next->content;
	if (i1 > i3 && i3 > i2)
		ra(a, "ra\n", 1);
	if (i1 < i2 && i1 > i3)
		rra(a, "rra\n", 1);
}

void	sort_4_nor(t_stack **a, t_stack **b)
{
	int	i1;
	int	i2;
	int	i3;
	int	i4;

	i1 = (*a)->pos;
	i2 = (*a)->next->pos;
	i3 = (*a)->next->next->pos;
	i4 = (*a)->next->next->next->pos;
	if (i3 == 0)
	{
		ra(a, "ra\n", 1);
		ra(a, "ra\n", 1);
		pa(a, b, "pb\n");
		sort_3(a);
		pa(b, a, "pa\n");
	}
	else if (i4 == 0)
	{
		rra(a, "rra\n", 1);
		pa(a, b, "pb\n");
		sort_3(a);
		pa(b, a, "pa\n");
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	i1;
	int	i2;
	int	i3;
	int	i4;

	i1 = (*a)->pos;
	i2 = (*a)->next->pos;
	i3 = (*a)->next->next->pos;
	i4 = (*a)->next->next->next->pos;
	if (i1 == 0)
	{
		pa(a, b, "pb\n");
		sort_3(a);
		pa(b, a, "pa\n");
	}
	else if (i2 == 0)
	{
		sa(a,"sa\n", 1);
		pa(a, b, "pb\n");
		sort_3(a);
		pa(b, a, "pa\n");
	}
	else
		sort_4_nor(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
	{
		if (get_pos(*a, min_pos(*a)) >= ft_lstsize(*a) / 2)
			while ((*a)->pos != min_pos(*a))
				rra(a, "rra\n", 1);
		else if (get_pos(*a, min_pos(*a)) < ft_lstsize(*a) / 2)
			while ((*a)->pos != min_pos(*a))
				ra(a, "ra\n", 1);
		if ((*a)->pos == min_pos(*a))
			pa(a, b, "pb\n");
	}
	sort_3(a);
	while (*b)
		pa(b, a, "pa\n");
}

void	sort_size(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	if (i < 3)
		sa(a,"sa\n", 1);
	else if (i <= 3)
		sort_3(a);
	else if (i <= 4)
		sort_4(a, b);
	else if (i <= 5)
		sort_5(a, b);
	else if (i > 5)
		sort_100(a, b, i);
}
