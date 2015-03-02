/*
** map.c for map in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:52:16 2015 Rémi DURAND
** Last update Mon Mar  2 14:19:47 2015 Rémi DURAND
*/

#include "lemipc.h"

char		map_max(char *map)
{
  int		v;
  char		max;

  max = 0;
  v = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] > max)
	max = map[v];
      ++v;
    }
  return (max + 1);
}

int		map_nb_minions(char *map)
{
  int		v;
  int	        nb;

  nb = 0;
  v = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] > 0)
	++nb;
      ++v;
    }
  return (nb);
}

int	        find_offset(char *map)
{
  int		v;
  int		count;

  v = 0;
  count = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] == 0)
	++count;
      else
	count = 0;
      if (count == 6)
	return (v);
      ++v;
    }
  return (-1);
}

int		fill_map(char nb_player, char *map)
{
  int		v;
  int		offset;

  v = 0;
  if ((offset = find_offset(map)) == (-1))
    return (-1);
  while (v != 7)
    {
      map[offset + v] = nb_player;
      ++v;
    }
  return (0);
}
