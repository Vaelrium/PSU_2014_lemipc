/*
** init.c for init in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:38:35 2015 Rémi DURAND
** Last update Mon Mar  2 14:09:19 2015 Rémi DURAND
*/

#include "lemipc.h"

int	        init_player(int map_id)
{
  char		nb_player;
  void		*addr;

  addr = shmat(map_id, NULL, SHM_W | SHM_R);
  if (map_nb_minions((char *)addr) >= ((MAP_SIZE / 3) * 2))
    return (-1);
  nb_player = map_max((char *)addr);  
  if (fill_map(nb_player, (char *)addr) == (-1))
    return (-1);
  if (nb_player == 1)
    display_map((char *)addr);
  return (0);
}
