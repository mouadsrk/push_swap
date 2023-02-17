/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:51:09 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/16 22:01:18 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	check_is_empty(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if(ft_isdigit(str[i]))
			j++;
		i++;
	}
	if(j == 0)
	{
		printf("error empty\n");
		exit(1);
	}
}


void check_sort(t_stack *a)
{
	int i;
	
	if(!a)
		return;
	i = a->content;
	while(a->next)
	{
		a = a->next;
		if(a->content > i)
		i = a->content;
		else
			return;
	}
	if(!a->next)
	{
		printf("it already sorted");
		exit(0);
	}
}

void check_numbers_digit(char *num)
{
	int i;
	int c;
	int j;

	j = 0;
	c = 0;
	i = -1;
	while(num[++i])
	{
		if(ft_isdigit(num[i]))
			c = 1;
		if (num[i] == '-')
			j++;
		if((c == 1 && num[i] == '-') || (num[i] != '-' && !ft_isdigit(num[i])))
		{
			printf("error; some arguments aren’t integers\n");
			exit(1);
		}
	}
	if(c != 1 || j > 1)
	{
		printf("error;> some arguments aren’t integers\n");
		exit(1);
	}
}

t_stack *make_stack(char **str)
{
	t_stack *a;
	int i;
	t_stack *tmp;
	
	i = 0;
	a = ft_lstnew(ft_atoi(str[i]));
	tmp = a;
	while(str[++i])
	{	
		tmp->next = ft_lstnew(ft_atoi(str[i]));
		tmp = tmp->next;
	}
	return(a);
}

void duplicat_number(t_stack *a)
{
	t_stack *tmp;
	t_stack *tmp2;
	tmp = a;

	while(tmp)
	{
		tmp2 = a;
		while(tmp2 != tmp)
		{
			if(tmp->content ==tmp2->content)
			{
				printf("Error duplicat number\n");
				exit(1);
			}
			tmp2=tmp2->next;
		}		
		tmp=tmp->next;
	}
}

int main (int argc, char **argv)
{
	t_data n;
	char **str;
	int i;
	int j;
	int w;
	t_stack *a ,*tmp,*b;
	b = NULL;
	if(argc == 1)
	{
		printf("Error arg!\n");
		exit(1);
	}
	i = 1;
	while(i < argc)
	{
		check_is_empty(argv[i]);
		n.num = ft_strjoin(n.num,argv[i]);
		i++;
	}
	str = ft_split(n.num,' ');
	free(n.num);
	i = -1;
	while (str[++i])
	{
		check_numbers_digit(str[i]);
	}
	a = make_stack(str);
	duplicat_number(a);
	check_sort(a);
	indice(a);
	// tmp = a;
	// while(tmp)
	// {
	// 	printf("indice = %d valeur %d\n",tmp->pos, tmp->content);
	// 	tmp = tmp->next;
	// }
	sort_size(&a,&b,ft_lstsize(a));
	tmp = a;
	while(tmp)
	{
		printf("indice = %d valeur %d\n",tmp->pos, tmp->content);
		tmp = tmp->next;
	}
	

}