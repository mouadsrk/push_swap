/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:42:11 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/28 21:52:51 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	ft_check(t_stack **a, t_stack	**b, char *read_buffer)
{
	if (!ft_strncmp("pa\n", read_buffer, 4))
		pa(b, a, "");
	else if (!ft_strncmp("pb\n", read_buffer, 4))
		pa(a, b, "");
	else if (!ft_strncmp("ra\n", read_buffer, 4))
		ra(a, "", 1);
	else if (!ft_strncmp("rb\n", read_buffer, 4))
		ra(b, "", 1);
	else if (!ft_strncmp("rr\n", read_buffer, 4))
		rr(a, b, 0);
	else if (!ft_strncmp("rra\n", read_buffer, 5))
		rra(a, "", 1);
	else if (!ft_strncmp("rrb\n", read_buffer, 5))
		rra(b, "", 1);
	else if (!ft_strncmp("rrr\n", read_buffer, 5))
		rrr(a, b, 0);
	else if (!ft_strncmp("sa\n", read_buffer, 4))
		sa(a, "", 0);
	else if (!ft_strncmp("sb\n", read_buffer, 4))
		sa(b, "", 0);
	else if (!ft_strncmp("ss\n", read_buffer, 4))
		ss(a, b, 0);
	else
		exit_error();
}

void	ft_check_read(t_stack **a, t_stack	**b)
{
	char	*read_buffer;

	read_buffer = get_next_line(0);
	while (read_buffer)
	{
		ft_check(a, b, read_buffer);
		free(read_buffer);
		read_buffer = get_next_line(0);
	}
}

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
		ft_check_read(&a, &b);
		if (check_sort(a) == 1 && !b)
			write(1, "OK\n", 3);
		else if (check_sort(a) == 0 || b)
			write(1, "KO\n", 3);
		ft_lstclear(&a);
		ft_lstclear(&b);
	}
}
