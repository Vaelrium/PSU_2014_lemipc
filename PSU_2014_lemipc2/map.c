/*
** map.c for map in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:52:16 2015 Rémi DURAND
** Last update Thu Mar  5 16:14:48 2015 Rémi DURAND
*/

#include "lemipc.h"

char		map_max(char *map)
{
  int		v;
  char		max;
  int		count;

  max = '0';
  count = 0;
  v = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] > max)
	max = map[v];
      ++v;
    }
  v = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] == max)
	++count;
      ++v;
    }
  return (count >= EQ_LIM ? max + 1 : max);
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

int		find_offset(char *map)
{
  int		v;
  int		ret;

  v = 0;
  while (v != 25)
    {
      ret = random() % 100;
      if (map[ret] == '0')
	return (ret);
      ++v;
    }
  v = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] == '0')
	return (v);
      ++v;
    }
  return (-1);
}

int		add_player(t_player *player, char *map)
{
  int		offset;

  if (player->eq > '9' || (offset = find_offset(map)) == (-1))
    return (-1);
  map[offset] = player->eq;
  player->x = X(offset);
  player->y = Y(offset);
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
