#pragma once

typedef struct PocketNode 
{
  char *key;
  char *val;
  struct PocketNode *next;  
} PocketNode;

typedef struct 
{
  PocketNode *begin;
  PocketNode *end;
} HTPocket;

typedef struct 
{
  HTPocket table[1024];
  unsigned int cap;
} HashTable;

HashTable HTinit();
//TODO : free
//! void HTfree(HashTable *ht);

void HTadd(HashTable *ht, char *key, char *val);
char* HTget(HashTable *ht, char *key);