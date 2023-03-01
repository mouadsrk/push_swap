/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:11:37 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/28 16:51:21 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = tmp->pos;
	while (tmp)
	{
		if (i > tmp->pos)
			i = tmp->pos;
		tmp = tmp->next;
	}
	return (i);
}

int	max_pos(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = tmp->pos;
	while (tmp)
	{
		if (i < tmp->pos)
			i = tmp->pos;
		tmp = tmp->next;
	}
	return (i);
}

int	get_pos(t_stack *a, int pos)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->pos == pos)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	calcule_chunk_and_middle(t_data *d, t_stack **a)
{
	d->tmp = d->chunck;
	if (ft_lstsize(*a) <= 100)
		d->num = 20;
	if (ft_lstsize(*a) <= 250 && ft_lstsize(*a) >= 100)
		d->num = 31;
	d->chunck = d->chunck + d->num;
	d->mid = d->tmp + d->num / 2;
}

void	get_chunck(t_stack *a, t_data *d)
{
	d->hlt_1 = -1;
	d->hlt_2 = -1;
	while (a)
	{
		if ((a->pos <= d->chunck && d->hlt_1 == -1))
		{
			d->hlt_1 = a->pos;
			d->hlt_2 = a->pos;
		}
		else if ((a->pos <= d->chunck && d->hlt_1 != -1))
			d->hlt_2 = a->pos;
		a = a->next;
	}
}
