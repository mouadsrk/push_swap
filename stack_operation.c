/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:36:59 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 19:01:11 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, char *str, int i)
{
	t_stack	*tmp;

	if (!a)
		return ;
	if (i == 1)
		write(1, str, ft_strlen(str));
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	sa(a, "sa\n", 0);
	sa(b, "sb\n", 0);
}

void	pa(t_stack **a, t_stack **b, char *str)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	write(1, str, ft_strlen(str));
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
}

void	ra(t_stack **a, char *str, int i)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*a)
		return ;
	if (i == 1)
		write(1, str, ft_strlen(str));
	tmp = *a;
	tmp2 = *a;
	*a = (*a)->next;
	while (tmp->next)
	tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	ra(a, "ra\n", 0);
	ra(b, "rb\n", 0);
}
