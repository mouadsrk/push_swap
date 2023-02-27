/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:35:51 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 16:38:35 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indice(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = a;
	while (a)
	{
		tmp = tmp2;
		while (tmp)
		{
			if (a->content >= tmp->content)
				a->pos += 1;
			tmp = tmp->next;
		}
		a = a->next;
	}
}

void	check_is_empty(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			j++;
		i++;
	}
	if (j == 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
}

int	check_sort(t_stack *a)
{
	int	i;
	int	j;

	if (!a)
		return (0);
	i = a->content;
	while (a->next)
	{
		a = a->next;
		if (a->content > i)
		i = a->content;
		else
			return (0);
	}
	return (1);
}

void	check_numbers_digit(char *num)
{
	int	i;
	int	c;
	int	j;

	j = 0;
	c = 0;
	i = -1;
	while (num[++i])
	{
		if (ft_isdigit(num[i]))
			c = 1;
		if (num[i] == '-' || num[i] == '+')
			j++;
		if ((c == 1 && (num[i] == '-' || num[i] == '+'))
			|| ((num[i] != '-' && num[i] != '+') && !ft_isdigit(num[i])))
		{
			write(1, "error\n", 6);
			exit(1);
		}
	}
	if (c != 1 || j > 1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
}

void	duplicat_number(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = a;
		while (tmp2 != tmp)
		{
			if (tmp->content == tmp2->content)
			{
				write(1, "error\n", 6);
				exit(1);
			}
			tmp2 = tmp2->next;
		}		
		tmp = tmp->next;
	}
}
