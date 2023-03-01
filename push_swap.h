/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:33:13 by mserrouk          #+#    #+#             */
/*   Updated: 2023/02/28 21:51:20 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct stract
{
	int		chunck;
	int		hlt_1;
	int		hlt_2;
	int		mv_1;
	int		mv_2;
	char	*str;
	char	**str2;
	int		num;
	int		tmp;
	int		mid;

}	t_data;

void	sa(t_stack **a, char *str, int i);
void	ss(t_stack **a, t_stack **b, int i);
void	pa(t_stack **a, t_stack **b, char *str);
void	ra(t_stack **a, char *str, int i);
void	rr(t_stack **a, t_stack **b, int i);
void	rra(t_stack **a, char *str, int i);
void	rrr(t_stack **a, t_stack **b, int i);
void	indice(t_stack *a);
void	sort_size(t_stack **a, t_stack **b, int i);
int		check_sort(t_stack *a);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);
void	sort_4(t_stack **a, t_stack **b);
int		min_pos(t_stack *a);
int		max_pos(t_stack *a);
int		get_pos(t_stack *a, int pos);
void	calcule_chunk_and_middle(t_data *d, t_stack **a);
void	get_chunck(t_stack *a, t_data *d);
int		push_b_data(t_data *d, t_stack **a);
void	get_stak_a(t_stack *b, t_data *d);
void	sort_100(t_stack **a, t_stack **b);
void	check_top(t_data *d, t_stack **a, t_stack **b);
void	check_down(t_data *d, t_stack **a, t_stack **b);
void	check_diver1(t_data *d, t_stack **a, t_stack **b);
void	check_diver2(t_data *d, t_stack **a, t_stack **b);
void	check_is_empty(char *str);
void	check_numbers_digit(char *num);
void	duplicat_number(t_stack *a);
void	parse(int argc, char **argv, t_data	*d);
t_stack	*make_stack(char **str);

#endif
