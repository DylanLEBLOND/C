/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-blon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:30:18 by dle-blon          #+#    #+#             */
/*   Updated: 2016/02/01 19:17:53 by dle-blon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/srcs/ft_printf.h"
#include <stdio.h>
#define STRING 0
#define NUM 0
#define CHARS 0
#define SHORTS 0
#define INTEGERS 0
#define LONGS 0
#define LLONGS 0
#define DECIMAL 0
#define BASES 0


int     main(void)
{
	long long a = -42;
	size_t b = -42;
	intmax_t c = -42;

//	printf("Printf :    OCT = <%jx> <%zx> <%llx> <%lx> <%x> <%hx> <%hhx>\n", c, b, a, -42l, -42, -42, -42);
//	ft_printf("ft_Printf : OCT = <%jx> <%zx> <%llx> <%lx> <%x> <%hx> <%hhx>\n", c, b, a, -42l, -42, -42, -42);
	printf("Printf :    OCT = <%#10.4o>\n", 42);
	ft_printf("ft_Printf : OCT = <%#10.4o>\n", 42);
	if (STRING)
	{
		printf("************** CHARACTERS ****************\n");
		
		printf("Printf :    CHAR = %c\n", 'A');
		ft_printf("ft_Printf : CHAR = %c\n", 'A');
		
		printf("Printf :    STRING 0 = <%s>\n", "Test");
		ft_printf("ft_Printf : STRING 0 = <%s>\n", "Test");
		
		printf("Printf :    STRING 1 = <%10s>\n", "Test");
		ft_printf("ft_Printf : STRING 1 = <%10s>\n", "Test");
		
		printf("Printf :    STRING 2 = <%10.0s>\n", "Test");
        ft_printf("ft_Printf : STRING 2 = <%10.0s>\n", "Test");

		printf("Printf :    STRING 3 = <%0.2s>\n", "Test");
        ft_printf("ft_Printf : STRING 3 = <%0.2s>\n", "Test");

		printf("Printf :    STRING 4 = <%-10s>\n", "Test");
		ft_printf("ft_Printf : STRING 4 = <%-10s>\n", "Test");
		
		printf("Printf :    STRING 5 = <%.4s>\n", "TestTest");
		ft_printf("ft_Printf : STRING 5 = <%.4s>\n", "Test");
		
		printf("Printf :    STRING 6 = <%10.4s>\n", "Test");
		ft_printf("ft_Printf : STRING 6 = <%10.4s>\n", "Test");
		
		printf("Printf :    STRING 7 = <%-10.4s>\n", "Test");
		ft_printf("ft_Printf : STRING 7 = <%-10.4s>\n", "Test");

		printf("Printf :    STRING 8 = <%10.4s>\n", "");
        ft_printf("ft_Printf : STRING 8 = <%10.4s>\n", "");

        printf("Printf :    STRING 9 = <%-10.4s>\n", "");
        ft_printf("ft_Printf : STRING 9 = <%-10.4s>\n", "");

		char *s = NULL;
		
		printf("Printf :    STRING 10 = <%10.4s>\n", s);
		ft_printf("ft_Printf : STRING 10 = <%10.4s>\n", s);

		printf("Printf :    STRING 11 = <%-10.4s>\n", s);
		ft_printf("ft_Printf : STRING 11 = <%-10.4s>\n", s);
	}
	if (NUM)
	{
		printf("************** NUMBERS ******************\n");

		signed char min = CHAR_MIN;
		signed char max = CHAR_MAX;
		unsigned char umax = UCHAR_MAX;
		short smin = SHRT_MIN;
		short smax = SHRT_MAX;
		unsigned short usmax = USHRT_MAX;
		unsigned int uimax = UINT_MAX;
		unsigned long ulmax = ULONG_MAX;
		unsigned long long ullmax = ULLONG_MAX;
		uintmax_t tmax = UINTMAX_MAX;
		ssize_t zmax = SSIZE_MAX;

		printf("Printf :    MIN CHAR = %hhd\n", min);
		ft_printf("ft_Printf : MIN CHAR = %hhd\n", min);
		printf("Printf :    MAX CHAR = %hhd\n", max);
		ft_printf("ft_Printf : MAX CHAR = %hhd\n", max);
		printf("Printf :    MAX UNSIGNED CHAR = %hhu\n", umax);
        ft_printf("ft_Printf : MAX UNSIGNED CHAR = %hhu\n", umax);
	
		printf("Printf :    MIN SHORT = %hd\n", smin);
		ft_printf("ft_Printf : MIN SHORT = %hd\n", smin);
		printf("Printf :    MAX SHORT = %hd\n", smax);
		ft_printf("ft_Printf : MAX SHORT = %hd\n", smax);
		printf("Printf :    MAX UNSIGNED SHORT = %hu\n", usmax);
        ft_printf("ft_Printf : MAX UNSIGNED SHORT = %hu\n", usmax);

		printf("Printf :    MIN INT = %d\n", INT_MIN);
		ft_printf("ft_Printf : MIN INT = %d\n", INT_MIN);
		printf("Printf :    MAX INT = %d\n", INT_MAX);
		ft_printf("ft_Printf : MAX INT = %d\n", INT_MAX);
		printf("Printf :    MAX UNSIGNED INT = %u\n", uimax);
        ft_printf("ft_Printf : MAX UNSIGNED INT = %u\n", uimax);
		
		printf("Printf :    MIN LONG = %ld\n", LONG_MIN);
		ft_printf("ft_Printf : MIN LONG = %ld\n", LONG_MIN);
		printf("Printf :    MAX LONG = %ld\n", LONG_MAX);
		ft_printf("ft_Printf : MAX LONG = %ld\n", LONG_MAX);
		printf("Printf :    MAX UNSIGNED LONG = %lu\n", ulmax);
        ft_printf("ft_Printf : MAX UNSIGNED LONG = %lu\n", ulmax);
		
		printf("Printf :    MIN LONG LONG = %lld\n", LLONG_MIN);
		ft_printf("ft_Printf : MIN LONG LONG = %lld\n", LLONG_MIN);
		printf("Printf :    MAX LONG LONG = %lld\n", LLONG_MAX);
		ft_printf("ft_Printf : MAX LONG LONG = %lld\n", LLONG_MAX);
		printf("Printf :    MAX UNSIGNED LONG LONG = %llu\n", ullmax);
		ft_printf("ft_Printf : MAX UNSIGNED LONG LONG = %llu\n", ullmax);

		printf("Printf :    MIN INTMAX_T = %jd\n", INTMAX_MIN);
		ft_printf("ft_Printf : MIN INTMAX_T = %jd\n", INTMAX_MIN);
		printf("Printf :    MAX INTMAX_T = %jd\n", INTMAX_MAX);
		ft_printf("ft_Printf : MAX INTMAX_T = %jd\n", INTMAX_MAX);
        printf("Printf :    MAX UINTMAX_T = %ju\n", tmax);
        ft_printf("ft_Printf : MAX UINTMAX_T = %ju\n", tmax);

		printf("Printf :    MIN SSIZE_T = %zd\n", SSIZE_MAX * -1 - 2);
		ft_printf("ft_Printf : MIN SSIZE_T = %zd\n", SSIZE_MAX * -1 - 2);
		printf("Printf :    MAX SSIZE_T = %zd\n", SSIZE_MAX);
		ft_printf("ft_Printf : MAX SSIZE_T = %zd\n", SSIZE_MAX);
        printf("Printf :    MAX SIZE_T = %zu\n", zmax);
        ft_printf("ft_Printf : MAX SIZE_T = %zu\n", zmax);
	}
	if (CHARS)
    {
		signed char n = 122;

        printf("Printf :    CHAR 1 = <%10.4hhd>\n", n);
        ft_printf("ft_Printf : CHAR 1 = <%10.4hhd>\n", n);

        printf("Printf :    CHAR 2 = <%-10.4hhd>\n", n);
        ft_printf("ft_Printf : CHAR 2 = <%-10.4hhd>\n", n);

        printf("Printf :    CHAR 3 = <%010hhd>\n", n);
        ft_printf("ft_Printf : CHAR 3 = <%010hhd>\n", n);

        printf("Printf :    CHAR 4 = <%010.4hhd>\n", n);
        ft_printf("ft_Printf : CHAR 4 = <%010.4hhd>\n", n);

		printf("Printf :    CHAR 5 = <%+10.4hhd>\n", n);
        ft_printf("ft_Printf : CHAR 5 = <%+10.4hhd>\n", n);

        printf("Printf :    CHAR 6 = <%+-10.4hhd>\n", n);
        ft_printf("ft_Printf : CHAR 6 = <%+-10.4hhd>\n", n);

        printf("Printf :    CHAR 7 = <%+010hhd>\n", n);
        ft_printf("ft_Printf : CHAR 7 = <%+010hhd>\n", n);

		printf("Printf :    CHAR 4 = <%+010.4hhd>\n", n);
        ft_printf("ft_Printf : CHAR 4 = <%+010.4hhd>\n", n);

        printf("Printf :    UNSIGNED 1 = <%10.4hhu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 1 = <%10.4hhu>\n", n);

        printf("Printf :    UNSIGNED 2 = <%-10.4hhu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 2 = <%-10.4hhu>\n", n);

        printf("Printf :    UNSIGNED 3 = <%010hhu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 3 = <%010hhu>\n", n);

        printf("Printf :    UNSIGNED 4 = <%010.4hhu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 4 = <%010.4hhu>\n", n);
    }
	if (SHORTS)
    {
		short n = 1234;

        printf("Printf :    SHORT 1 = <%10.4hd>\n", n);
		ft_printf("ft_Printf : SHORT 1 = <%10.4hd>\n", n);

        printf("Printf :    SHORT 2 = <%-10.4hd>\n", n);
		ft_printf("ft_Printf : SHORT 2 = <%-10.4hd>\n", n);

        printf("Printf :    SHORT 3 = <%010hd>\n", n);
		ft_printf("ft_Printf : SHORT 3 = <%010hd>\n", n);

        printf("Printf :    SHORT 4 = <%010.4hd>\n", n);
		ft_printf("ft_Printf : SHORT 4 = <%010.4hd>\n", n);

		printf("Printf :    SHORT 5 = <%+10.4hd>\n", n);
        ft_printf("ft_Printf : SHORT 5 = <%+10.4hd>\n", n);

        printf("Printf :    SHORT 6 = <%+-10.4hd>\n", n);
        ft_printf("ft_Printf : SHORT 6 = <%+-10.4hd>\n", n);

        printf("Printf :    SHORT 7 = <%+010hd>\n", n);
        ft_printf("ft_Printf : SHORT 7 = <%+010hd>\n", n);

        printf("Printf :    SHORT 8 = <%+010.4hd>\n", n);
        ft_printf("ft_Printf : SHORT 8 = <%+010.4hd>\n", n);

        printf("Printf :    UNSIGNED 1 = <%10.4hu>\n", n);
		ft_printf("ft_Printf : UNSIGNED 1 = <%10.4hu>\n", n);

        printf("Printf :    UNSIGNED 2 = <%-10.4hu>\n", n);
		ft_printf("ft_Printf : UNSIGNED 2 = <%-10.4hu>\n", n);

        printf("Printf :    UNSIGNED 3 = <%010hu>\n", n);
		ft_printf("ft_Printf : UNSIGNED 3 = <%010hu>\n", n);

        printf("Printf :    UNSIGNED 4 = <%010.4hu>\n", n);
		ft_printf("ft_Printf : UNSIGNED 4 = <%010.4hu>\n", n);
    }
	if (INTEGERS)
	{
		printf("Printf :    INTEGER 1 = <%10.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 1 = <%10.4d>\n", 1234);

        printf("Printf :    INTEGER 2 = <%-10.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 2 = <%-10.4d>\n", 1234);

        printf("Printf :    INTEGER 3 = <%010d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 3 = <%010d>\n", 1234);

        printf("Printf :    INTEGER 4 = <%010.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 4 = <%010.4d>\n", 1234);

		printf("Printf :    INTEGER 5 = <%+10.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 5 = <%+10.4d>\n", 1234);

        printf("Printf :    INTEGER 6 = <%+-10.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 6 = <%+-10.4d>\n", 1234);

        printf("Printf :    INTEGER 7 = <%+010d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 7 = <%+010d>\n", 1234);

        printf("Printf :    INTEGER 8 = <%+010.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 8 = <%+010.4d>\n", 1234);

		printf("Printf :    INTEGER 9 = <%010.4d>\n", -1234);
        ft_printf("ft_Printf : INTEGER 9 = <%010.4d>\n", -1234);

        printf("Printf :    INTEGER 10 = <%+-10.4d>\n", -1234);
        ft_printf("ft_Printf : INTEGER 10 = <%+-10.4d>\n", -1234);

        printf("Printf :    INTEGER 11 = <%+010d>\n", -1234);
        ft_printf("ft_Printf : INTEGER 11 = <%+010d>\n", -1234);

        printf("Printf :    INTEGER 12 = <%+010.4d>\n", -1234);
        ft_printf("ft_Printf : INTEGER 12 = <%+010.4d>\n", -1234);

		printf("Printf :    INTEGER 13 = <% 10.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 13 = <% 10.4d>\n", 1234);

		printf("Printf :    INTEGER 14 = <% -10.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 14 = <% -10.4d>\n", 1234);

		printf("Printf :    INTEGER 15 = <% 010d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 15 = <% 010d>\n", 1234);

		printf("Printf :    INTEGER 16 = <% 010.4d>\n", 1234);
        ft_printf("ft_Printf : INTEGER 16 = <% 010.4d>\n", 1234);

        printf("Printf :    INTEGER 18 = <%+ 10.4d>\n", -1234);
        ft_printf("ft_Printf : INTEGER 18 = <%+ 10.4d>\n", -1234);

        printf("Printf :    INTEGER 19 = <% -10.4d>\n", -1234);
        ft_printf("ft_Printf : INTEGER 19 = <% -10.4d>\n", -1234);

        printf("Printf :    INTEGER 20 = <% 010d>\n", -1234);
        ft_printf("ft_Printf : INTEGER 20 = <% 010d>\n", -1234);

		printf("Printf :    INTEGER 21 = <% 010.4d>\n", -1234);
        ft_printf("ft_Printf : INTEGER 21 = <% 010.4d>\n", -1234);

        printf("Printf :    UNSIGNED 1 = <%10.4u>\n", 1234);
        ft_printf("ft_Printf : UNSIGNED 1 = <%10.4u>\n", 1234);

        printf("Printf :    UNSIGNED 2 = <%-10.4u>\n", 1234);
        ft_printf("ft_Printf : UNSIGNED 2 = <%-10.4u>\n", 1234);

        printf("Printf :    UNSIGNED 3 = <%010u>\n", 1234);
        ft_printf("ft_Printf : UNSIGNED 3 = <%010u>\n", 1234);

        printf("Printf :    UNSIGNED 4 = <%010.4u>\n", 1234);
        ft_printf("ft_Printf : UNSIGNED 4 = <%010.4u>\n", 1234);
	}
	if (LONGS)
    {
		long n = 67848878122324;

        printf("Printf :    LONG 1 = <%20.4ld>\n", n);
        ft_printf("ft_Printf : LONG 1 = <%20.4ld>\n", n);

        printf("Printf :    LONG 2 = <%-20.4ld>\n", n);
        ft_printf("ft_Printf : LONG 2 = <%-20.4ld>\n", n);

        printf("Printf :    LONG 3 = <%020ld>\n", n);
        ft_printf("ft_Printf : LONG 3 = <%020ld>\n", n);

        printf("Printf :    LONG 4 = <%020.4ld>\n", n);
        ft_printf("ft_Printf : LONG 4 = <%020.4ld>\n", n);

		printf("Printf :    LONG 5 = <%+20.4ld>\n", n);
        ft_printf("ft_Printf : LONG 5 = <%+20.4ld>\n", n);

        printf("Printf :    LONG 6 = <%+-20.4ld>\n", n);
        ft_printf("ft_Printf : LONG 6 = <%+-20.4ld>\n", n);

        printf("Printf :    LONG 7 = <%+020ld>\n", n);
        ft_printf("ft_Printf : LONG 7 = <%+020ld>\n", n);

        printf("Printf :    LONG 8 = <%+020.4ld>\n", n);
        ft_printf("ft_Printf : LONG 8 = <%+020.4ld>\n", n);

        printf("Printf :    UNSIGNED 1 = <%20.4lu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 1 = <%20.4lu>\n", n);

        printf("Printf :    UNSIGNED 2 = <%-20.4lu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 2 = <%-20.4lu>\n", n);

        printf("Printf :    UNSIGNED 3 = <%020lu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 3 = <%020lu>\n", n);

        printf("Printf :    UNSIGNED 4 = <%020.4lu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 4 = <%020.4lu>\n", n);
    }
	if (LLONGS)
    {
        long long n = 67848878122324;

        printf("Printf :    LONG LONG 1 = <%20.4lld>\n", n);
        ft_printf("ft_Printf : LONG LONG 1 = <%20.4lld>\n", n);

        printf("Printf :    LONG LONG 2 = <%-20.4lld>\n", n);
        ft_printf("ft_Printf : LONG LONG 2 = <%-20.4lld>\n", n);

        printf("Printf :    LONG LONG 3 = <%020lld>\n", n);
        ft_printf("ft_Printf : LONG LONG 3 = <%020lld>\n", n);

        printf("Printf :    LONG LONG 4 = <%020.4lld>\n", n);
        ft_printf("ft_Printf : LONG LONG 4 = <%020.4lld>\n", n);

		printf("Printf :    LONG LONG 5 = <%+20.4lld>\n", n);
        ft_printf("ft_Printf : LONG LONG 5 = <%+20.4lld>\n", n);

        printf("Printf :    LONG LONG 6 = <%+-20.4lld>\n", n);
        ft_printf("ft_Printf : LONG LONG 6 = <%+-20.4lld>\n", n);

        printf("Printf :    LONG LONG 7 = <%+020lld>\n", n);
        ft_printf("ft_Printf : LONG LONG 7 = <%+020lld>\n", n);

        printf("Printf :    LONG LONG 8 = <%+020.4lld>\n", n);
        ft_printf("ft_Printf : LONG LONG 8 = <%+020.4lld>\n", n);

        printf("Printf :    UNSIGNED 1 = <%20.4llu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 1 = <%20.4llu>\n", n);

        printf("Printf :    UNSIGNED 2 = <%-20.4llu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 2 = <%-20.4llu>\n", n);

        printf("Printf :    UNSIGNED 3 = <%020llu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 3 = <%020llu>\n", n);

        printf("Printf :    UNSIGNED 4 = <%020.4llu>\n", n);
        ft_printf("ft_Printf : UNSIGNED 4 = <%020.4llu>\n", n);
    }
    if (DECIMAL)
    {
    	printf("Printf :    FLOAT 1 = <%f>\n", 10.0f);
		ft_printf("ft_Printf : FLOAT 1 = <%f>\n", 10.0f);

       	printf("Printf :    FLOAT 1 = <%f>\n", 10.4513f);
 		ft_printf("ft_Printf : FLOAT 1 = <%f>\n", 10.4513f);

 		printf("Printf :    FLOAT 1 = <%f>\n", -10.0f);
 		ft_printf("ft_Printf : FLOAT 1 = <%f>\n", -10.0f);

 		printf("Printf :    FLOAT 1 = <%f>\n", -10.4513f);
 		ft_printf("ft_Printf : FLOAT 1 = <%f>\n", -10.4513f);
    }
	if (BASES)
	{
		long a = -3000000000;
		
		printf("Printf :    oct = <%o>\n", a);
		ft_printf("ft_printf : oct = <%o>\n", a);
		
		printf("Printf :    hex = <%lx>\n", a);
		ft_printf("ft_printf : hex = <%lx>\n", a);
	
		printf("Printf :    oct = <%20lo>\n", a);
		ft_printf("ft_printf : oct = <%20lo>\n", a);
		
		printf("Printf :    hex min = <%20lx>\n", a);
		ft_printf("ft_printf : hex min = <%20lx>\n", a);
		
		printf("Printf :    hex maj = <%20lX>\n", a);
		ft_printf("ft_printf : hex maj = <%20lX>\n", a);
		
		printf("Printf :    oct = <%-20lo>\n", a);
		ft_printf("ft_printf : oct = <%-20lo>\n", a);
		
		printf("Printf :    hex min = <%-20lx>\n", a);
		ft_printf("ft_printf : hex min = <%-20lx>\n", a);
		
		printf("Printf :    hex maj = <%-20lX>\n", a);
		ft_printf("ft_printf : hex maj = <%-20lX>\n", a);
		
		printf("Printf :    oct = <%020lo>\n", a);
		ft_printf("ft_printf : oct = <%020lo>\n", a);
		
		printf("Printf :    hex min = <%020lx>\n", a);
		ft_printf("ft_printf : hex min = <%020lx>\n", a);
		
		printf("Printf :    hex maj = <%020lX>\n", a);
		ft_printf("ft_printf : hex maj = <%020lX>\n", a);
		
		printf("Printf :    oct = <%#8lo>\n", a);
		ft_printf("ft_printf : oct = <%#8lo>\n", a);
		
		printf("Printf :    hex min = <%#8lx>\n", a);
		ft_printf("ft_printf : hex min = <%#8lx>\n", a);
		
		printf("Printf :    hex maj = <%#8lX>\n", a);
		ft_printf("ft_printf : hex maj = <%#8lX>\n", a);
		
		printf("Printf :    oct = <%#-8lo>\n", a);
		ft_printf("ft_printf : oct = <%#-8lo>\n", a);
		
		printf("Printf :    hex min = <%#-8lx>\n", a);
		ft_printf("ft_printf : hex min = <%#-8lx>\n", a);
		
		printf("Printf :    hex maj = <%#-8lX>\n", a);
		ft_printf("ft_printf : hex maj = <%#-8lX>\n", a);
		
		printf("Printf :    oct = <%#08lo>\n", a);
		ft_printf("ft_printf : oct = <%#08lo>\n", a);
		
		printf("Printf :    hex min = <%#08lx>\n", a);
		ft_printf("ft_printf : hex min = <%#08lx>\n", a);
		
		printf("Printf :    hex maj = <%#08lX>\n", a);
		ft_printf("ft_printf : hex maj = <%#08lX>\n", a);
		
		ft_printf("encode64, %B\n", "Marster S6 easy bro $");
		ft_printf("binaire : %020b\n", a);
	}
	return (0);
}
