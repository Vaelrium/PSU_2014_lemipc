/*
** display.c for display in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 14:04:07 2015 Rémi DURAND
** Last update Mon Mar  2 14:07:59 2015 Rémi DURAND
*/

#include "lemipc.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		display_map(char *map)
{
  int		v;

  v = 0;
  while (v < MAP_SIZE)
    {
      my_putchar(map[v] + 48);
      if ((v % 10) == 0)
	my_putchar('\n');
      ++v;
    }
}
