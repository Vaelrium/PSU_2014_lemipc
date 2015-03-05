/*
** init.c for init in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:38:35 2015 Rémi DURAND
** Last update Thu Mar  5 12:57:47 2015 Rémi DURAND
*/

#include "lemipc.h"

int		algo_player(t_player *player, char *map, key_t key)
{
  int		sm_q_id[2];
  struct sembuf	sops;

  sm_q_id[0] = semget(key, 0, SHM_R | SHM_W);
  sops = sembuf_init(0, 0, 0);
  while (player->not_dead)
    {
      sem_set(sm_q_id[0], &sops, -1);
      moves(player, map);
      sem_set(sm_q_id[0], &sops, 1);
      usleep(300000);
    }
  return (0);
}

int		algo_first(t_player *player, char *map, key_t key)
{
  int		sm_q_id[2];
  struct sembuf	sops;

  sm_q_id[0] = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
  sops = sembuf_init(0, 1, 0);
  sem_set(sm_q_id[0], &sops, 1);
  while (player->not_dead)
    {
      sem_set(sm_q_id[0], &sops, -1);
      moves(player, map);
      sem_set(sm_q_id[0], &sops, 1);
      first_aff(map);
    }
  while (1)
    first_aff(map);
  return (0);
}

int		is_first(char *map)
{
  int		v;
  int		count;

  v = 0;
  count = 0;
  while (v != MAP_SIZE)
    {
      if (map[v] == '1')
	++count;
      if (map[v] > '1' || count > 1)
	return (-1);
      ++v;
    }
  return (0);
}

int	        init_player(int map_id, key_t key)
{
  t_player      player;
  char		*addr;

  srandom(time(NULL));
  addr = (char *)shmat(map_id, NULL, SHM_W | SHM_R);
  if (map_nb_minions(addr) > 63)
    return (-1);
  player.eq = map_max(addr);
  player.not_dead = 1;
  if (add_player(&player, addr) == (-1))
    return (-1);
  if (player.eq == '1' && is_first(addr) == 0)
    {
      write(1, "\e[0;0H\e[2J\e[?25l", 19);
      algo_first(&player, addr, key);
    }
  else
    algo_player(&player, addr, key);
  return (0);
}
