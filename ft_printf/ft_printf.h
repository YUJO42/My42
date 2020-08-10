/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:23:29 by yujo              #+#    #+#             */
/*   Updated: 2020/08/10 21:58:00 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define ON 1
# define OFF 0
# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct	s_struct
{
	va_list		va;
	int			count;
	int			width;  // 전체의 폭
	int			dot;	// . = 자리수 표시
	int			zero;	// 0 = 공백만큼 0채움
	int			minus;  // -
	int			precision;	// * = precision
	char		specifier; // 서싟지정자
}				t_struct;

/*
*******************************************************************************
** 	ft_printf.c																  *
*******************************************************************************
*/

int				ft_printf(const char *format, ...);
void			parsing_process(char *format, t_struct *tag);
void			reset_struct(t_struct *tag);

/*
*******************************************************************************
** 	ft_printf_utils.c														  *
*******************************************************************************
*/

int 			ft_putchar(char c);

/*
*******************************************************************************
** 	ft_printf_parser.c														  *
*******************************************************************************
*/

void			flag_parser(char **format, t_struct *tag);
void			width_parser(char **format, t_struct *tag);
void			precision_parser(char **format, t_struct *tag);
void			specifier_parser(char **format, t_struct *tag);
void			specifier_print(t_struct *tag);

/*
*******************************************************************************
** 	ft_printf_string.c ('s', 'c', '%')										  *
*******************************************************************************
*/

void			print_string(t_struct *tag);

/*
*******************************************************************************
** 	ft_printf_number.c ('p', 'd', 'i', 'u', 'x', 'X')						  *
*******************************************************************************
*/

void			print_number(t_struct *tag);

#endif
