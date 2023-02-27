/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:18:29 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 14:39:22 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b_data(t_data *d, t_stack **a, t_stack **b)
{
	if (!*a)
		return (1);
	get_chunck(*a, d);
	if (d->hlt_2 == -1 && d->hlt_1 == -1)
		return (1);
	d->mv_1 = get_pos(*a, d->hlt_1);
	d->mv_2 = ft_lstsize(*a) - get_pos(*a, d->hlt_2) + 1;
	return (0);
}

void	get_stak_a(t_stack *b, t_data *d)
{
	d->hlt_1 = -1;
	d->hlt_2 = -1;
	d->hlt_1 = max_pos(b);
	d->hlt_2 = min_pos(b);
	while (b)
	{
		if (d->hlt_2 < b->pos && b->pos != d->hlt_1)
			d->hlt_2 = b->pos;
		b = b->next;
	}
}
