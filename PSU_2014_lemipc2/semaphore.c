/*
** semaphore.c for  in /home/ganesha/projets/PSU_2014_lemipc
**
** Made by Ambroise Coutarel
** Login   <ganesha@epitech.net>
**
** Started on  Mon Mar  2 15:53:47 2015 Ambroise Coutarel
** Last update Thu Mar  5 16:18:54 2015 Rémi DURAND
*/

#include "lemipc.h"

struct sembuf	sembuf_init(int sem_num, int sem_op, int sem_flg)
{
  struct sembuf	ret;

  ret.sem_num = sem_num;
  ret.sem_flg = sem_flg;
  ret.sem_op = sem_op;
  return (ret);
}

int		sem_set(int sem_id, struct sembuf *ops, int value)
{
  ops->sem_op = value;
  return (semop(sem_id, ops, 1));
}
