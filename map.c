/*
** map.c for map in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:52:16 2015 Rémi DURAND
** Last update Mon Mar  2 13:24:22 2015 Rémi DURAND
*/

#include "lemipc.h"

char		map_max(char *map)
{
  int		v;
  char		max;

  max = 1;
  v = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] > max)
	max = map[v];
      ++v;
    }
  return (max);
}

int		map_nb_minions(char *map)
{
  int		v;
  int	        nb;

  max = 0;
  v = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] > 0)
	++nb;
      ++v;
    }
  return (nb);
}

int		fill_map(char nb_player, char *map)
{
  int		max_of;
  int		max_length;
  int		v;

  v = 0;
  max_length = 0;
  while (v != MAP_SIZE)
    {
      if ()
      ++v;
    }
}
