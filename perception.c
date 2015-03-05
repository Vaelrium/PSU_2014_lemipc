/*
** perception_check.c for lemipc in /home/ganesha/projets/PSU_2014_lemipc
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar  4 15:15:21 2015 Ambroise Coutarel
** Last update Thu Mar  5 15:06:02 2015 Rémi DURAND
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

void	sendMessage(int msgq_id, t_msg *msg, int remaining, long type)
{
  int	i;

  i = 0;
  msg->mtype = type;
  msg->str[0] = '0';
  while (i != remaining)
    {
      msgsnd(msgq_id, &msg, sizeof(t_msg), 0);
      i++;
    }
}

char	nbTeam(char *map)
{
  int	i;
  char	first;

  i = 0;
  first = '0';
  while (i != MAP_SIZE)
    {
      if (map[i] != '0' && first == '0')
	first = map[i];
      if (first != map[i] && map[i] != '0')
	return (0);
      ++i;
    }
  return (-1);
}
