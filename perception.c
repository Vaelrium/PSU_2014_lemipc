/*
** perception_check.c for lemipc in /home/ganesha/projets/PSU_2014_lemipc
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar  4 15:15:21 2015 Ambroise Coutarel
** Last update Wed Mar  4 15:31:35 2015 Ambroise Coutarel
*/

#include "lemipc.h"

int	checkForEnemies(t_player *player, char *map, int block)
{
  int	pos;
  int	ret;

  ret = 0;
  pos = (player->y * 10) + player->x;
  if ((pos - block) >= 0 && map[pos - block] != player->eq && 
      map[pos - block] != '0')
    ++ret;
  if ((pos + block) <= 99 && map[pos + block] != player->eq && 
      map[pos + block] != '0')
    ++ret;
  
  return (ret);
}
