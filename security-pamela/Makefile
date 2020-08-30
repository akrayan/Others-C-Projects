##
## Makefile for Makefile in /home/billel/encode/pamela
## 
## Made by BIllel
## Login   <billel.mouhoub@epitech.eu>
## 
## Started on  Wed Nov 22 16:26:52 2017 BIllel
## Last update Wed Nov 29 19:13:41 2017 BIllel
##

CC		=	gcc

RM		=	rm -f

NAME		=	mypam.so

SU		=	sudo

GREEN		=	\033[0;32m

RED		=	\033[0;31m

CFLAGS		=	-I./include -fPIC -fno-stack-protector -c

SRC		=	src/pamela.c \
			encode_src/chained_list_gestion.c \
			encode_src/create_encoded_file.c \
			encode_src/create_encoded_file2.c \
			encode_src/crypto.c \
			encode_src/directory_get_names.c \
			encode_src/main.c

OBJ		=	./*.o ./src/*.o

PAM_FOLDER	=	/lib/x86_64-linux-gnu/security

PAM_CONF	=	/etc/pam.d

AUTH_FILE	=	common-auth

ACCOUNT_FILE	=	common-account

TEST_NAME	=	pam_test

TEST_SRC	=	test/test.c

CHECKER		=	sudo grep -rnw $(PAM_CONF) -e $(NAME)

$(NAME)		:
			$(CC) $(CFLAGS) $(SRC)

all		:	$(NAME)

install		:
			@$(SU) ld -x --shared -o $(PAM_FOLDER)/$(NAME) pamela.o
			@$(SU) sed -i '1 i\auth sufficient mypam.so' $(PAM_CONF)/$(AUTH_FILE)
			@$(SU) sed -i '2 i\account sufficient mypam.so' $(PAM_CONF)/$(AUTH_FILE)
			@$(SU) sed -i '1 i\auth sufficient mypam.so' $(PAM_CONF)/$(ACCOUNT_FILE)
			@$(SU) sed -i '2 i\account sufficient mypam.so' $(PAM_CONF)/$(ACCOUNT_FILE)
			@echo "${GREEN}Installed${NC}"

uninstall	:
			@$(SU) $(RM) $(PAM_FOLDER)/$(NAME)
			@$(SU) sed -i '/auth sufficient mypam.so/d' $(PAM_CONF)/$(AUTH_FILE)
			@$(SU) sed -i '/account sufficient mypam.so/d' $(PAM_CONF)/$(AUTH_FILE)
			@$(SU) sed -i '/auth sufficient mypam.so/d' $(PAM_CONF)/$(ACCOUNT_FILE)
			@$(SU) sed -i '/account sufficient mypam.so/d' $(PAM_CONF)/$(ACCOUNT_FILE)
			@echo "${GREEN}Uninstalled${NC}"
			$(CHECKER = 0) 

test		:
			@$(RM) $(TEST_NAME) test/*.o
			@$(CC) -o $(TEST_NAME) $(TEST_SRC) -lpam -lpam_misc
			./$(TEST_NAME) backdoor
			@$(RM) $(TEST_NAME) test/*.o

check		:
			@$(CHECKER)
			@if [ $$? -eq 0 ] ; then echo "${GREEN}MyPAM is already installed${NC}" ; else echo "$(RED)MyPam not found${NC}" ; fi

clean		:
			$(RM) $(OBJ) $(TEST_NAME)

re		:	clean all

.PHONY		:	test check
