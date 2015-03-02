/*
** display.c for display in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 14:04:07 2015 Rémi DURAND
** Last update Mon Mar  2 14:31:54 2015 Rémi DURAND
*/

#include "lemipc.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		display_map(char *map)
{
  int		v;

  v = 1;
  while (v < (MAP_SIZE + 1))
    {
      my_putchar(map[v - 1] + 48);
      my_putchar(' ');
      if ((v % 10) == 0 && v > 8)
	my_putchar('\n');
      ++v;
    }
}
