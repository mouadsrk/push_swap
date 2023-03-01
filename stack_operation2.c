/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:27:56 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/28 21:52:55 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, char *str, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!a || ft_lstsize((*a)) < 2)
		return ;
	if (i == 1)
		write(1, str, ft_strlen(str));
	tmp = *a;
	tmp2 = *a;
	while (tmp->next)
	tmp = tmp->next;
	while (tmp2->next != tmp)
	tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *a;
	*a = tmp;
}

void	rrr(t_stack **a, t_stack **b, int i)
{
	if (i == 1)
		write(1, "rrr\n", 4);
	rra(a, "rra\n", 0);
	rra(b, "rrb\n", 0);
}
