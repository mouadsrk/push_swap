/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:51:09 by mserrouk          #+#    #+#             */
/*   Updated: 2023/03/01 20:47:01 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	d;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc >= 2)
	{
		parse(argc, argv, &d);
		a = make_stack(d.str2);
		ft_free(d.str2, ft_word(d.str, ' '));
		free(d.str);
		duplicat_number(a);
		if (check_sort(a) == 1)
			exit(0);
		indice(a);
		sort_size(&a, &b, ft_lstsize(a));
		ft_lstclear(&a);
	}
}
