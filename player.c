/*
** init.c for init in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:38:35 2015 Rémi DURAND
** Last update Mon Mar  2 18:49:11 2015 Rémi DURAND
*/

#include "lemipc.h"

int		algo_player(int nb_player, char *map, key_t key)
{
  int		sm_q_id[2];
  struct sembuf	sops;

  sops = sembuf_init();
  sm_q_id[0] = semget(key, 0, SHM_R | SHM_W);
  sem_set(sm_q_id[0], &sops, 1);
  while (42)
    {
      if (semctl(sm_q_id[0], 0, GETVAL) == (nb_player - 48))
	{
	  sem_set(sm_q_id[0], &sops, -1);
	}
    }
  (void)map;
  return (0);
}

int		algo_first(char *map, key_t key)
{
  int		sm_q_id[2];
  struct sembuf	sops;

  sops = sembuf_init();
  sm_q_id[0] = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
  while (42)
    {
      if (semctl(sm_q_id[0], 0, GETVAL) == 1)
	{
	  write(1, "\e[1;1H\e[2J", 12);
	  display_map(map);
	  sem_set(sm_q_id[0], &sops, map_max(map) - 50);
	}
    }
}

int	        init_player(int map_id, key_t key)
{
  char		nb_player;
  char		*addr;

  addr = (char *)shmat(map_id, NULL, SHM_W | SHM_R);
  if (map_nb_minions(addr) >= ((MAP_SIZE / 3) * 2))
    return (-1);
  nb_player = map_max(addr);
  if (fill_map(nb_player, addr) == (-1))
    return (-1);
  if (nb_player == '1')
    algo_first(addr, key);
  else
    algo_player(nb_player, addr, key);
  return (0);
}
