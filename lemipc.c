/*
** lemipc.c for lemipc in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:14:48 2015 Rémi DURAND
** Last update Mon Mar  2 17:12:15 2015 Rémi DURAND
*/

#include "lemipc.h"

int		main()
{
  char		path[PATH_MAX + 1];
  key_t		key;
  int		shm_id;

  if (!getcwd(path, PATH_MAX))
    return (-1);
  key = ftok(path, 0);
  shm_id = shmget(key, MAP_SIZE, SHM_R | SHM_W);
  if (shm_id == (-1))
    {
      shm_id = shmget(key, MAP_SIZE, IPC_CREAT | SHM_R | SHM_W);
      init_map(shm_id);
      if (init_player(shm_id, key) == (-1))
	return (-1);
    }
  else if (init_player(shm_id, key) == (-1))
    return (-1);
  return (0);
}
