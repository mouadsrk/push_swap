/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:36:20 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 19:38:01 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_diver1(t_data *d, t_stack **a, t_stack **b)
{
	if (d->mv_1 <= ft_lstsize(*b) - d->mv_2 + 2)
	{
		while ((*b)->pos != d->hlt_1)
			ra(b, "rb\n", 1);
		if ((*b)->pos == d->hlt_1)
			pa(b, a, "pa\n");
		while ((*b)->pos != d->hlt_2)
			rra(b, "rrb\n", 1);
		if ((*b)->pos == d->hlt_2)
			pa(b, a, "pa\n");
	}
	else if (d->mv_1 > ft_lstsize(*b) - d->mv_2 + 2)
	{
		while ((*b)->pos != d->hlt_2)
			rra(b, "rrb\n", 1);
		if ((*b)->pos == d->hlt_2)
			pa(b, a, "pa\n");
		while ((*b)->pos != d->hlt_1)
			ra(b, "rb\n", 1);
		if ((*b)->pos == d->hlt_1)
			pa(b, a, "pa\n");
		sa(a,"sa\n", 1);
	}
}

void	check_diver2(t_data *d, t_stack **a, t_stack **b)
{
	if (d->mv_2 <= ft_lstsize(*b) - d->mv_1 + 2)
	{
		while ((*b)->pos != d->hlt_2)
			ra(b, "rb\n", 1);
		if ((*b)->pos == d->hlt_2)
			pa(b, a, "pa\n");
		while ((*b)->pos != d->hlt_1)
			rra(b, "rrb\n", 1);
		if ((*b)->pos == d->hlt_1)
			pa(b, a, "pa\n");
		if (d->hlt_2 != d->hlt_1)
			sa(a,"sa\n", 1);
	}
	else if (d->mv_2 > ft_lstsize(*b) - d->mv_1 + 2)
	{
		while ((*b)->pos != d->hlt_1)
			rra(b, "rrb\n", 1);
		if ((*b)->pos == d->hlt_1)
			pa(b, a, "pa\n");
		while ((*b)->pos != d->hlt_2)
			ra(b, "rb\n", 1);
		if ((*b)->pos == d->hlt_2)
			pa(b, a, "pa\n");
	}
}
