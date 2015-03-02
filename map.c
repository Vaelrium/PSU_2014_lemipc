/*
** map.c for map in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:52:16 2015 Rémi DURAND
** Last update Mon Mar  2 18:13:32 2015 Rémi DURAND
*/

#include "lemipc.h"

char		map_max(char *map)
{
  int		v;
  char		max;

  max = '0';
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
      if (map[v] > '0')
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
      if (map[v] == '0')
	++count;
      else
	count = 0;
      if (count == 8)
	return (v - 6);
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

void		init_map(int shm_id)
{
  int		v;
  char		*map;

  v = 0;
  map = (char *)shmat(shm_id, NULL, SHM_W);
  while (v != MAP_SIZE)
    {
      map[v] = '0';
      ++v;
    }
}
