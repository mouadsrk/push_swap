/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:28:32 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/22 09:35:48 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void sort_3(t_stack **a)
{
	int i1;
	int i2;
	int i3;

	if(!*a)
		return;
	i1 = (*a)->content;
	i2 = (*a)->next->content;
	i3 = (*a)->next->next->content;
	if((i1 > i2 && i1 < i3) || (i1 > i2 && i2 > i3) || (i1 < i3 && i3 < i2))
		sa(a ,"sa\n");
	i1 = (*a)->content;
	i2 = (*a)->next->content;
	i3 = (*a)->next->next->content;
	if(i1 > i3 && i3 > i2)
		ra(a , "ra\n");
	if(i1 < i2 && i1> i3)
		rra(a , "rra\n");
}

void sort_4_nor(t_stack **a,t_stack **b)
{
	int i1;
	int i2;
	int i3;
	int i4;

	i1 = (*a)->pos;
	i2 = (*a)->next->pos;
	i3 = (*a)->next->next->pos;
	i4 = (*a)->next->next->next->pos;
	if(i3 == 0)
	{
		ra(a ,"ra\n");
		ra(a , "ra\n");
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a,"pa\n");
	}
	else if(i4 == 0)
	{
		rra(a, "rra\n");
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a ,"pa\n");
	}
}


void sort_4(t_stack **a,t_stack **b)
{
	int i1;
	int i2;
	int i3;
	int i4;

	i1 = (*a)->pos;
	i2 = (*a)->next->pos;
	i3 = (*a)->next->next->pos;
	i4 = (*a)->next->next->next->pos;
	if(i1 == 0)
	{
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a, "pa\n");
	}
	else if(i2 == 0)
	{
		sa(a, "sa\n");
		pa(a,b , "pb\n");
		sort_3(a);
		pa(b,a ,"pa\n");
	}
	else
	sort_4_nor(a,b);
}

int min_pos(t_stack *a)
{
	t_stack *tmp;
	int i;

	tmp = a;
	i = tmp->pos;
	while(tmp)
	{
		if(i > tmp->pos)
			i = tmp->pos;
		tmp = tmp->next;
	}
	return i;
}

int max_pos(t_stack *a)
{
	t_stack *tmp;
	int i;

	tmp = a;
	i = tmp->pos;
	while(tmp)
	{
		if(i < tmp->pos)
			i = tmp->pos;
		tmp = tmp->next;
	}
	return i;
}

int get_pos(t_stack *a,int pos)
{
	int i;

	i = 0;
	while(a)
	{
		if(a->pos == pos)
			return i;
		a = a->next;
		i++;
	}
	return -1;
}


void sort_5(t_stack **a,t_stack **b)
{
	while(ft_lstsize(*a) > 3)
	{
		if (get_pos(*a ,min_pos(*a)) >= ft_lstsize(*a) /2)
			while((*a)->pos != min_pos(*a))
				rra(a ,"rra\n");
		else if (get_pos(*a ,min_pos(*a)) < ft_lstsize(*a) /2)
			while((*a)->pos != min_pos(*a))
				ra(a, "ra\n");
		if((*a)->pos == min_pos(*a))
			pa(a,b, "pb\n");
	}
	sort_3(a);
	while(*b)
		pa(b,a , "pa\n");
}


void get_chunck(t_stack *a,t_data *d)
{
	d->holt_first = -1;
	d->holt_second = -1;
	while(a)
	{
		if((a->pos <= d->chunck && d->holt_first == -1))
		{
			d->holt_first = a->pos;
			d->holt_second = a->pos;
		}
		else if((a->pos <= d->chunck && d->holt_first != -1))
			d->holt_second = a->pos;
		a = a->next;
	}
}

int middle_chunk(t_data d,int size)
{
	int mid;

	if(d.chunck <= 19)
		mid = size / 2;
	if(d.chunck > size && d.chunck > 19)
		mid = ((d.chunck - 20) + size) / 2     ;
	if ((d.chunck <= size && d.chunck > 19))
		mid = d.chunck - 10 ;
		return mid;
}



int push_b(t_data *d, t_stack **a ,  t_stack **b , int mid, int l)
{
	if(!*a)
		return 1;
	get_chunck(*a,d);
	// printf("%d>\n",d->holt_first);
	// printf("%d>\n",d->holt_second);
	if(d->holt_second == -1 && d->holt_first == -1)
	{
		// printf("%d>\n",d->holt_first);
		// printf("%d>\n",d->holt_second);
		return 1;
	}
	d->first_move = get_pos(*a,d->holt_first);
	d->seconde_move = ft_lstsize(*a) - get_pos(*a,d->holt_second) + 1 ;
	// printf("%d>\n",d->holt_first);
	// printf("%d>\n",d->holt_second);
	// printf("1m%d\n",d->first_move);
	// printf("2m%d\n",d->seconde_move);
	if(d->first_move <= d->seconde_move)
	{
		while((*a)->pos != d->holt_first)
			ra(a,"ra\n");
		if((*a)->pos == d->holt_first)
			{
				pa(a , b, "pb\n");
				if((*b)->pos <= mid && ft_lstsize(*b) > 2 && l != 1)
						ra(b,"rb\n");
			}
		}
	else
	{
	while((*a)->pos != d->holt_second && d->holt_second != -1)
			rra(a,"rra\n");
	if((*a)->pos == d->holt_second)
	{
		pa(a , b, "pb\n");
			if((*b)->pos <= mid && ft_lstsize(*b) > 2 && l != 1)
				ra(b,"rb\n");
	}
	}
	return 0;
}

void get_stak_a(t_stack *b,t_data *d)
{
	d->holt_first = -1;
	d->holt_second = -1;
	d->holt_first = max_pos(b);
	d->holt_second = min_pos(b);
	// if(d->holt_first == d->holt_second)
	// {
	// 	d->holt_second = -1;
	// 	return;
	// }
	while(b)
	{
		if(d->holt_second < b->pos && b->pos != d->holt_first)
			d->holt_second = b->pos;
		b = b->next;
	}
}


void check_top(t_data *d,t_stack **a,t_stack **b)
{
	// write(1,"check_top\n",10);
	if(d->first_move <= d->seconde_move)
		{
			while ((*b)->pos != d->holt_second)
			{
				if((*b)->pos == d->holt_first)
					pa(b,a,"pa\n");
				if((*b)->pos == d->holt_second)
					break;
				ra(b,"rb\n");
			}
			if((*b)->pos == d->holt_second)
				pa(b,a,"pa\n");
		}
	else if(d->first_move > d->seconde_move)
	{
		while ((*b)->pos != d->holt_first)
		{
			if((*b)->pos == d->holt_second)
				pa(b,a,"pa\n");
			if((*b)->pos == d->holt_first)
				break;
			ra(b,"rb\n");
		}
		if((*b)->pos == d->holt_first)
			pa(b,a,"pa\n");
			sa(a,"sa\n");
	}
}

void check_down(t_data *d,t_stack **a,t_stack **b)
{
	// write(1,"check_down\n",11);
	if(d->first_move >= d->seconde_move)
		{
			while ((*b)->pos != d->holt_second)
			{
				if((*b)->pos == d->holt_first)
					pa(b,a,"pa\n");
				if((*b)->pos == d->holt_second)
					break;
				rra(b,"rrb\n");
			}
			if((*b)->pos == d->holt_second)
				pa(b,a,"pa\n");
		}
	else if(d->first_move < d->seconde_move)
	{
		while ((*b)->pos != d->holt_first)
		{
			if((*b)->pos == d->holt_second)
					pa(b,a,"pa\n");
			if((*b)->pos == d->holt_first)
				break;
			rra(b,"rrb\n");
		}
		if((*b)->pos == d->holt_first)
				pa(b,a,"pa\n");
			sa(a,"sa\n");
	}
}

void check_diver1(t_data *d,t_stack **a,t_stack **b)
{
	// write(1,"check_diver1\n",13);
	if(d->first_move <= ft_lstsize(*b) - d->seconde_move + 2)
	{
		while ((*b)->pos != d->holt_first)
			ra(b,"rb\n");
		if((*b)->pos == d->holt_first)
			pa(b,a,"pa\n");
		while ((*b)->pos != d->holt_second)
			rra(b,"rrb\n");
		if((*b)->pos == d->holt_second)
			pa(b,a,"pa\n");
	}
	else if (d->first_move > ft_lstsize(*b) - d->seconde_move + 2)
	{
		while ((*b)->pos != d->holt_second)
			rra(b,"rrb\n");
		if((*b)->pos == d->holt_second)
			pa(b,a,"pa\n");
		while ((*b)->pos != d->holt_first)
			ra(b,"rb\n");
		if((*b)->pos == d->holt_first)
				pa(b,a,"pa\n");
			sa(a,"sa\n");
	}
}

void check_diver2(t_data *d,t_stack **a,t_stack **b)
{
	// write(1,"check_diver2\n",13);
	if (d->seconde_move <= ft_lstsize(*b) - d->first_move + 2)
	{
		while ((*b)->pos != d->holt_second )
			ra(b,"rb\n");
		if((*b)->pos == d->holt_second)
			pa(b,a,"pa1\n");
		while ((*b)->pos != d->holt_first)
			rra(b,"rrb\n");
		if((*b)->pos == d->holt_first)
				pa(b,a,"pa\n");
		if(d->holt_second != d->holt_first)
				sa(a,"sa\n");
	}
	else if(d->seconde_move > ft_lstsize(*b) - d->first_move + 2)
	{
		while((*b)->pos != d->holt_first)
			rra(b,"rrb\n");
		if((*b)->pos == d->holt_first)
			pa(b,a,"pa\n");
		while ((*b)->pos != d->holt_second)
			ra(b,"rb\n");
		if((*b)->pos == d->holt_second)
			pa(b,a,"pa\n");
	}
}


void push_a(t_data *d,t_stack **a,t_stack **b)
{
	int size;
	if(!*b)
		return ;
	get_stak_a(*b,d);
	// printf(">%d\n",d->holt_first );
	// printf(">>%d\n",d->holt_second );
	if(d->holt_second == -1 && d->holt_first == -1)
		return ;
	if(d->holt_second == d->holt_first)
	{
		pa(b,a,"pa\n");
		return ;	
	}
	d->first_move = get_pos(*b,d->holt_first);
	d->seconde_move = get_pos(*b,d->holt_second);
	size = ft_lstsize(*b);
    // if(d->holt_first == 13)
    // {
    //     printf("%d\n",d->first_move );
    //      printf("%d\n",d->seconde_move );
    // }
	if (d->first_move <= size /2 && d->seconde_move <= size /2)
		check_top(d,a,b);
	else if (d->first_move >= size /2 && d->seconde_move >= size /2)
		check_down(d,a,b);
	else if(d->first_move <= size /2 && d->seconde_move >= size /2)
		check_diver1(d,a,b);
	else if(d->first_move >= size /2 && d->seconde_move <= size /2)
		check_diver2(d,a,b);
}



void sort_100(t_stack **a,t_stack **b, int i)
{
	t_data d;
	int num;
	int j;
	int m;
	int l = 0;
	int tmp;
	t_stack *tmp1;
	d.chunck = -1;
	j = 1;
	num = i  / 9 +  i % 9  ;
	if(ft_lstsize(*a) <= 100)
			num = i  / 4 +  i % 4  ;
	while(*a)
	{
		tmp = d.chunck;
		if(ft_lstsize(*a) <= 100)
		{
			// l = 1;
			num = i  / 12 +  i % 12 ;
		}
		d.chunck = d.chunck + num;
		m = 0;
		// printf("-------------");
		while(!m)
		{
			// printf(">>>>>>>>>>>\n");
			// printf("chunck = %d\n", d.chunck);
			// printf("mide = %d\n",tmp + num / 2);
			m = push_b(&d,a,b,tmp + num / 2,l);
			// printf(">>>>>>>>>>>\n");
		}
		j++;
	}
	// 
	// while(tmp1)
	// {
	// 	printf("<%d>\n",tmp1->pos);
	// 	tmp1= tmp1->next;
	// }

	int k = 0;
	while((*b) != NULL)
	{
        
		push_a(&d,a,b);
    // if (k == 486)
    //     break;
	}
	// printf("size b = %d",ft_lstsize(*b));
	// printf("size a= %d",ft_lstsize(*a));
}






void sort_size(t_stack **a,t_stack **b,int i)
{
	t_stack *tmp;
	if(i < 3)
		sa(a , "sa\n ");
	if(i <= 3)
		sort_3(a);
	else if(i <= 4)
		sort_4(a,b);
	else if(i <= 5)
		sort_5(a,b);
	else  if (i   <= 100)
		sort_100(a,b ,i);
	else  if (i   > 100)
		sort_100(a,b ,i);
}













// void check_size(t_stack **a,int size)
// {
// 	t_stack *tmp;
// 	t_stack *tmp2;

// 	tmp = *a;
// 	while(tmp)
// 	{
// 		tmp2 = *a;
// 		while(tmp2 != tmp->next)
// 		{
// 			if(tmp->content >= tmp2->content)
// 				tmp->log += 1;
// 			tmp2 = tmp2->next;
// 		}
// 		tmp = tmp->next;
// 	}
// }


// void sort_100(t_stack **a,t_stack **b ,int size)
// {
// 	t_stack *tmp;

// 	int	i ;

// 	check_size(a , size);
// 	*a = ft_lstlast(*a);
// 	i = (*a)->log - 1;
// 	while((*a)->previous)
// 	{
// 		tmp = *a;
// 		while(tmp->previous)
// 		{
// 			if((*a)->log < tmp->log && tmp->log <= i)
// 			{
// 				(*a)->dis = 0;
// 				break;
// 			}
// 			tmp = tmp->previous;
// 		}
// 		if((*a)->dis == 1)
// 			i = (*a)->log - 1;
// 		tmp = (*a);
// 		while(tmp->previous)
// 		{
// 			if((*a)->dis == 1 && (*a)->content < tmp->content && (*a)->log >= tmp->log )
// 				(tmp)->dis = 0;
// 			tmp = tmp->previous;
// 		}
// 		(*a) =(*a)->previous;
// 	}
// 	*a = ft_lstfirst(*a);
// 	tmp = (*a);


// }
