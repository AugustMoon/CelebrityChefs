/*-------------------------------------------------------------------------*
 *---									---*
 *---		memoryNoNos.c						---*
 *---									---*
 *---	    This program makes all kinds of mistakes with C strings.	---*
 *---	Fix them!  If you choose to make fixed-length arrays make them	---*
 *---	no bigger than 'MAX_STRING'.  'MAX_STRING' is too small for	---*
 *---	most applications, and that is the point.  We want to prove	---*
 *---	that even if the strings are too small we are not subject to	---*
 *---	buffer overflow attacks.					---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1.0		Joseph Phillips		2013 October 22	---*
 *---									---*
 *-------------------------------------------------------------------------*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#define		MAX_STRING	20

char*	getFirstName	(char*	firstName
			)
{
  printf("Please enter your first name: ");
  fgets(firstName,MAX_STRING,stdin);
  return(firstName);
}


char*	getLastName	(
			)
{
  char*	lastName = malloc(MAX_STRING*sizeof(char));;

  printf("Please enter your last name: ");
  fgets(lastName,MAX_STRING,stdin);
  return(lastName);
}


char*	getNickName	(char*	nickName
			)
{
  printf("Please enter your nick name: ");
  fgets(nickName,MAX_STRING,stdin);
  return(nickName);
}


char*	getCompleteName	(const char*	firstName,
			 const char*	lastName,
			 const char*	nickName,
			 char* 		completeName
			)
{
  snprintf(completeName,MAX_STRING,"%s %s %s",firstName,nickName,lastName);
  return(completeName);
}


int	main	()
{
  char*		firstName;
  char*		lastName;
  char*		nickName;
  char*		completeName;

  firstName = malloc(MAX_STRING*sizeof(char));
  nickName = malloc(MAX_STRING*sizeof(char));
  completeName = malloc(MAX_STRING*sizeof(char));

  firstName	= getFirstName(firstName);
  printf("firstName : %s\n", firstName);
  lastName	= getLastName();
  printf("lastName : %s\n", lastName);
  nickName	= getNickName(nickName);
  printf("nickName : %s\n", nickName);



  completeName	= getCompleteName(firstName,lastName,nickName,completeName);
  printf("Hello %s.\n",completeName);

  free (firstName);
  free (lastName);
  free (nickName);
  free (completeName);
  return(EXIT_SUCCESS);
}
