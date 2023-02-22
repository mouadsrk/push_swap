/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:51:09 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/22 03:05:51 by mserrouk         ###   ########.fr       */
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


int  check_sort(t_stack *a)
{
	int i;
	int j;
	j = -1; 
	if(!a)
		return (0);
	i = a->content;
	while(a->next)
	{
		j++;
		a = a->next;
		if(a->content > i)
		i = a->content;
		else
		{
			// printf("<%d>",j);
			return (0);
		}
	}
	return (1);
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
		tmp->next->previous = tmp;
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
	int fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd,1);
	close(fd);
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
	// if(check_sort(a))
	// 	exit(0);
	indice(a);
	// tmp = a;
	// while (tmp)
	// {
	// 	printf("%d\n",tmp->pos);
	// 	tmp =tmp->next;
	// }
	
	sort_size(&a,&b,ft_lstsize(a));
	if (check_sort(a))
		printf("\nsorted ");
	else
	printf("\n not sorted ");
	// make_list(&a);
	// while (tmp)
	// {
	// 	printf("%d\n",tmp->pos);
	// 	tmp =tmp->next;
	// }
	
	
}