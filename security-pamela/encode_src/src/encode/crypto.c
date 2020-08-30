/*
** crypto.c for crypto in /home/billel/encode/pamela/encode/src
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Sun Nov 26 23:32:11 2017 BIllel
** Last update Wed Nov 29 17:46:04 2017 BIllel
*/

#include "pamela_encode.h"

void handleErrors(void)
{
  ERR_print_errors_fp(stderr);
  abort();
}

int initSSL()
{
  ERR_load_crypto_strings();
  OpenSSL_add_all_algorithms();
}

int exitSSL()
{
  EVP_cleanup();
  ERR_free_strings();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
	    unsigned char *iv, unsigned char *ciphertext)
{
  EVP_CIPHER_CTX *ctx;
  int len;
  int ciphertext_len;
  
  if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
  if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    handleErrors();
  if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
    handleErrors();
  ciphertext_len = len;
  if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
  ciphertext_len += len;
  EVP_CIPHER_CTX_free(ctx);
  return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
	    unsigned char *iv, unsigned char *plaintext)
{
  EVP_CIPHER_CTX *ctx;
  int len;
  int plaintext_len;

  if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
  if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    handleErrors();
  if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
    handleErrors();
  plaintext_len = len;
  if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
  plaintext_len += len;
  EVP_CIPHER_CTX_free(ctx);
  return plaintext_len;
}

t_cryptmsg	encryption(char *str, int len)
{
  unsigned char *key = (unsigned char *)"the32characterareforthekey{+=^(-";
  unsigned char *iv = (unsigned char *)"thisisthesecreti";
  unsigned char *ciphertext = malloc(len * 2);
  int ciphertext_len;
  t_cryptmsg	msg;

  ciphertext_len = encrypt (str, len, key, iv,
			    ciphertext);
  msg.msg = ciphertext;
  msg.len = ciphertext_len;
  return (msg);
}

char *decryption(t_cryptmsg msg)
{
  unsigned char *key = (unsigned char *)"the32characterareforthekey{+=^(-";
  unsigned char *iv = (unsigned char *)"thisisthesecreti";
  unsigned char *decryptedtext = malloc(msg.len);
  int decryptedtext_len;

  decryptedtext_len = decrypt(msg.msg, msg.len, key, iv,
			      decryptedtext);
  decryptedtext[decryptedtext_len] = '\0';
  return (decryptedtext);
}

/*int main (void)
{
  char *str = (char *)"Mon msg a tester";
  
  t_cryptmsg msg = encryption(str, strlen(str));
  char *result = decryption(msg);
  
  printf("%s\n", result);
  free(msg.msg);
  free(result);
  return 0;
  }
*/
