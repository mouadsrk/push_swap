/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:22:17 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 19:38:01 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_top_norm(t_data *d, t_stack **a, t_stack **b)
{
	while ((*b)->pos != d->hlt_1)
	{
		if ((*b)->pos == d->hlt_2)
			pa(b, a, "pa\n");
		if ((*b)->pos == d->hlt_1)
			break ;
		ra(b, "rb\n", 1);
	}
	if ((*b)->pos == d->hlt_1)
		pa(b, a, "pa\n");
	sa(a,"sa\n", 1);
}

void	check_top(t_data *d, t_stack **a, t_stack **b)
{
	if (d->mv_1 <= d->mv_2)
	{
		while ((*b)->pos != d->hlt_2)
		{
			if ((*b)->pos == d->hlt_1)
				pa(b, a, "pa\n");
			if ((*b)->pos == d->hlt_2)
				break ;
			ra(b, "rb\n", 1);
		}
		if ((*b)->pos == d->hlt_2)
			pa(b, a, "pa\n");
	}
	else if (d->mv_1 > d->mv_2)
	{
		check_top_norm(d, a, b);
	}
}

void	check_down_norm(t_data *d, t_stack **a, t_stack **b)
{
	while ((*b)->pos != d->hlt_1)
	{
		if ((*b)->pos == d->hlt_2)
			pa(b, a, "pa\n");
		if ((*b)->pos == d->hlt_1)
			break ;
		rra(b, "rrb\n", 1);
	}
	if ((*b)->pos == d->hlt_1)
		pa(b, a, "pa\n");
	sa(a,"sa\n", 1);
}

void	check_down(t_data *d, t_stack **a, t_stack **b)
{
	if (d->mv_1 >= d->mv_2)
	{
		while ((*b)->pos != d->hlt_2)
		{
			if ((*b)->pos == d->hlt_1)
				pa(b, a, "pa\n");
			if ((*b)->pos == d->hlt_2)
				break ;
			rra(b, "rrb\n", 1);
		}
		if ((*b)->pos == d->hlt_2)
			pa(b, a, "pa\n");
	}
	else if (d->mv_1 < d->mv_2)
	{
		check_down_norm(d, a, b);
	}
}
