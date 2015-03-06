/*
** perception_check.c for lemipc in /home/ganesha/projets/PSU_2014_lemipc
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Wed Mar  4 15:15:21 2015 Ambroise Coutarel
** Last update Fri Mar  6 17:31:04 2015 Ambroise Coutarel
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
  t_msg	test;

  (void)msg;
  i = 0;
  bzero(&test, sizeof(t_msg));
  //printf("Using message queue %d\n", msgq_id);
  while (i != remaining)
    {
      test.mtype = type;
      //sprintf(test.mtext, "JEFF!!!");
      msgsnd(msgq_id, &test, sizeof(t_msg), 0);
      /* if (msgsnd(msgq_id, &test, sizeof(t_msg), 0) == (-1)) */
      /* 	printf("ERROR : %s, message type : %ld\n", strerror(errno), test.mtype); */
      /* else */
      /* 	printf("Message %ld sent with success\n", test.mtype); */
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

void	affEnd(int sm_q_id[2])
{
  write(1, "End\n", 4);
  sleep(5);
  semctl(sm_q_id[0], IPC_RMID, 0);
  msgctl(sm_q_id[1], IPC_RMID, NULL);
}
