/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:42:11 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/27 19:38:38 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_check(t_stack **a,t_stack	**b, char * read_buffer)
{
	if(!ft_strncmp("pa\n",read_buffer,5))
		pa(a, b, "");
	else if(!ft_strncmp("pb\n",read_buffer,5))
		pa(b, a, "");
	else if(!ft_strncmp("ra\n",read_buffer,5))
		ra(a,"",1);
	else if(!ft_strncmp("rb\n",read_buffer,5))
		ra(b,"",1);
	else if(!ft_strncmp("rr\n",read_buffer,5))
		rr(a, b);
	else if(!ft_strncmp("rra\n",read_buffer,5))
		rra(a, "", 1);
	else if(!ft_strncmp("rrb\n",read_buffer,5))
		rra(b, "", 1);
	else if(!ft_strncmp("rrr\n",read_buffer,5))
		rrr(a, b);
	else if(!ft_strncmp("sa\n",read_buffer,5))
		sa(a,"", 0);
	else if(!ft_strncmp("sb\n",read_buffer,5))
		sa(b,"", 0);
	else if(!ft_strncmp("ss\n",read_buffer,5))
		ss(a, b);
	else
	{
		write(1,"Error\n",7);
		exit(1);
	}
	
}

void ft_check_read(t_stack **a,t_stack	**b)
{
	char read_buffer[10];
	int i;
	
	i = 1;
	while(i)
	{
		i = read(1,read_buffer,10);
		if(i != 0)
			ft_check(a ,b ,read_buffer);
	}
	
}

int main (int argc, char **argv)
{
    t_data	d;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	parse(argc, argv, &d);
    a = make_stack(d.str2);
	
	ft_free(d.str2, ft_word(d.str, ' '));
	free(d.str);
	duplicat_number(a);
	ft_check_read(&a, &b);
	if(check_sort(a) == 1)
		write(1 ,"OK", 2);
	else
		write(1 ,"KO", 2);
}