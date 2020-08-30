/*
** create_encoded_file.c for encoded file in /home/billel/encode/pamela/encode/src
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Sat Nov 25 22:06:19 2017 BIllel
** Last update Wed Nov 29 19:07:08 2017 BIllel
*/

#include "pamela_encode.h"

int	get_long_size2(t_elem *file_names)
{
  int	tmp = -1;

  while (file_names != NULL)
    {
      if (tmp < file_names->size)
	tmp = file_names->size;
      file_names = file_names->next;
    }
  return (tmp + strlen(CONTAINER_FOLDER));
}

void	create_directory2(t_elem *file_names)
{
  t_elem	*tmp = file_names;
  int		long_size_dir = get_long_size2(tmp);
  char		dir_to_create[long_size_dir];
  struct stat st = {0};

  while (tmp != NULL)
    {
      memset(dir_to_create, 0, long_size_dir);
      sprintf(dir_to_create, "%s%s/", CONTAINER_FOLDER, tmp->dir);
      if (stat(dir_to_create, &st) == -1) {
	if ((mkdir(dir_to_create, 0700)) == -1)
	  perror("mkdir");
      }
      tmp = tmp->next;
    }
}

void	write_in_file_encode2(t_file *myFile)
{
  int		byte = 0;
  t_cryptmsg	myMsg;

  memset(myFile->data, 0, READ_BUFFER_SIZE);
  write(1, "crypting...\n", 12);
  while ((byte = read(myFile->old_fd, myFile->data, READ_BUFFER_SIZE - 1)) > 0)
    {
      myFile->data[byte] = 0;
      myMsg = encryption(myFile->data, byte);
      if ((write(myFile->new_fd, myMsg.msg, myMsg.len)) == -1)
	perror("write");
    }
  write(1, "finished...\n", 12);
  exitSSL();
}

void	create_file_encoded2(t_elem *file_names)
{
  t_elem	*tmp = file_names;
  t_file	*myFile;
  int		long_size = get_long_size2(file_names);
  char		path_to_create[long_size];

  if (STRUCT_FILE_MEMORY_ALLOCATION)
    exit(EXIT_FAILURE);
  initSSL();
  create_directory2(tmp);
  while (file_names != NULL)
    { 
      memset(path_to_create, 0, long_size);
      myFile->name = file_names->path;
      sprintf(path_to_create, "%s/%s", CONTAINER_FOLDER, myFile->name);
      if ((myFile->old_fd = open(myFile->name, O_RDONLY)) == -1)
	{printf("Opening file %s failed\n", myFile->name);perror("open");exit(EXIT_FAILURE);}
      if (file_names->type == 'f' && (myFile->new_fd = open(path_to_create, O_RDWR | O_APPEND | O_CREAT, 0777)) == -1)
	{printf("Creating file %s failed\n", path_to_create);perror("open");exit(EXIT_FAILURE);}

      write_in_file_encode2(myFile);
      
      close(myFile->old_fd);
      close(myFile->new_fd);

      file_names = file_names->next;
    }  
  free(myFile);
}
