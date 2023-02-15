/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:51:09 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/15 01:35:15 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int check_numbers_digit(char *num)
{
	int i;
	int c;
	
	c = 0;
	i = 0;
	while(num[i])
	{
		if(ft_isdigit(num[i]))
		c = 1; 
		if ((ft_isdigit(num[i]) || num[i] == ' ' )|| 
		(num[i] == '-' && num[i + 1] != '-'))
		i++;
		else
		{
			printf("error; some arguments aren’t integers\n");
			exit(1);
		}
	}
	if(c == 1)
		return 1;
	printf("error; some arguments aren’t integers\n");
	exit(1);
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
	t_stack *a;
	if(argc == 1)
	{
		printf("Error arg!\n");
		exit(1);
	}
	i = 1;
	while(i < argc)
	{
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
}



















	// i = 0;
	// j = 0;
	// while (str[i])
	// {
	// 	check_numbers(str[i]);
	// 	j = 0;
	// 	while(j < i)
	// 	{
	// 		if(i != j && !ft_strncmp(str[i],str[j], 11))
	// 			{
	// 				printf("Error duplicat number\n");
	// 				exit(1);	
	// 			}
	// 		j++;
	// 	}
	// 	printf("%s\n",str[i]);
	// 	i++;
	// }