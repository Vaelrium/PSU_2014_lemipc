/*
** display.c for display in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 14:04:07 2015 Rémi DURAND
** Last update Thu Mar  5 12:59:26 2015 Rémi DURAND
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
      write(1, &map[v], MAP_SIDE);
      my_putchar('\n');
      v += 10;
    }
}

void		first_aff(char *map)
{
  write(1, "\e[0;0H", 7);
  display_map(map);
  usleep(300000);
}
