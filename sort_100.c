/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:11:50 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/28 21:50:43 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(t_data *d, t_stack **a, t_stack **b)
{
	int	m;

	m = push_b_data(d, a);
	if (m == 1)
		return (1);
	while ((*a)->pos != d->hlt_1
		&& (d->hlt_1 != d->hlt_2 || d->mv_1 <= d->mv_2))
		ra(a, "ra\n", 1);
	while ((*a)->pos != d->hlt_2 && (d->hlt_1 == d->hlt_2 && d->mv_1 > d->mv_2))
		rra(a, "rra\n", 1);
	if ((*a)->pos == d->hlt_1 || (*a)->pos == d->hlt_2)
		pa(a, b, "pb\n");
	if (push_b_data(d, a) == 0)
	{
		if ((*a)->pos != d->hlt_1 && d->mv_1 <= d->mv_2
			&& (*b)->pos <= d->mid && ft_lstsize(*b) > 2)
			rr(a, b, 1);
		else if ((*b)->pos <= d->mid && ft_lstsize(*b) > 2)
			ra(b, "rb\n", 1);
	}
	else if ((*b)->pos <= d->mid && ft_lstsize(*b) > 2)
		ra(b, "rb\n", 1);
	return (0);
}

void	push_a(t_data *d, t_stack **a, t_stack **b)
{
	int	size;

	if (!*b)
		return ;
	get_stak_a(*b, d);
	if (d->hlt_2 == -1 && d->hlt_1 == -1)
		return ;
	if (d->hlt_2 == d->hlt_1)
	{
		pa(b, a, "pa\n");
		return ;
	}
	d->mv_1 = get_pos(*b, d->hlt_1);
	d->mv_2 = get_pos(*b, d->hlt_2);
	size = ft_lstsize(*b);
	if (d->mv_1 <= size / 2 && d->mv_2 <= size / 2)
		check_top(d, a, b);
	else if (d->mv_1 >= size / 2 && d->mv_2 >= size / 2)
		check_down(d, a, b);
	else if (d->mv_1 <= size / 2 && d->mv_2 >= size / 2)
		check_diver1(d, a, b);
	else if (d->mv_1 >= size / 2 && d->mv_2 <= size / 2)
		check_diver2(d, a, b);
}

void	sort_100(t_stack **a, t_stack **b)
{
	t_data	d;
	int		m;

	d.chunck = -1;
	d.num = 56 ;
	while (*a)
	{
		calcule_chunk_and_middle(&d, a);
		m = 0;
		while (!m)
		{
			m = push_b(&d, a, b);
		}
	}
	while ((*b))
	{
		push_a(&d, a, b);
	}
}
