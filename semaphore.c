/*
** semaphore.c for  in /home/ganesha/projets/PSU_2014_lemipc
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  2 15:53:47 2015 Ambroise Coutarel
** Last update Mon Mar  2 16:26:56 2015 Ambroise Coutarel
*/

#include "lemipc.h"

struct sembuf	sembuf_init()
{
  struct sembuf	ret;

  ret.sem_num = 0;
  ret.sem_flg = 0;
  ret.sem_op = 0;
  return (ret);
}

int	sem_set(int sem_id, struct sembuf *ops, int value)
{
  ops->sem_op = value;
  return (semop(sem_id, ops, 1)); 
}
