/*
** pamela_encode.h for pamela_encode in /home/billel/encode/bilbil/include
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Sat Nov 25 21:42:10 2017 BIllel
** Last update Wed Nov 29 18:07:29 2017 BIllel
*/

#ifndef PAMELA_ENCODE_H_
# define PAMELA_ENCODE_H_

#include "list.h"
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

# define CONTAINER_FOLDER		"./container"
# define PATH_TO_ENCRYPT		"/home"
# define READ_BUFFER_SIZE		8192
# define STRUCT_FILE_MEMORY_ALLOCATION	((myFile = malloc(sizeof(t_file))) == NULL) || (((myFile->data = (char *)malloc(sizeof(char) * READ_BUFFER_SIZE)) == NULL))

typedef struct  s_cryptmsg
{
  char          *msg;
  int           len;
}               t_cryptmsg;

typedef struct	s_file
{
  int	old_fd;
  char	*name;
  char	*data;
  int	new_fd;
}		t_file;

/* MAIN */
int	main(void);

/* DIRECTORY_GET_NAMES */
t_elem  *scDir(char *nameDir, t_elem *list);

/* CREATE_ENCODED_FILE_C_ */
void	create_file_encoded(t_elem *file_names);
void	create_directory(t_elem *file_names);
int	get_long_size(t_elem *file_names);
int	get_long_size_dir(t_elem *file_names);

/* CRYPTO_C_ */
t_cryptmsg	encryption(char *str, int len);
char		*decryption(t_cryptmsg msg);
int		initSSL();
int		exitSSL();

#endif /* !PAMELA_ENCODE */
