/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:52:05 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 16:59:49 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*make_stack(char **str)
{
	t_stack	*a;
	int		i;
	t_stack	*tmp;

	i = 0;
	a = ft_lstnew(ft_atoi(str[i]));
	tmp = a;
	while (str[++i])
	{
		tmp->next = ft_lstnew(ft_atoi(str[i]));
		tmp = tmp->next;
	}
	return (a);
}

void	parse(int argc, char **argv, t_data	*d)
{
	int		i;

	if (argc == 1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		check_is_empty(argv[i]);
		d->str = ft_strjoin(d->str, argv[i]);
		i++;
	}
	d->str2 = ft_split(d->str, ' ');
	i = -1;
	while (d->str2[++i])
		check_numbers_digit(d->str2[i]);
}