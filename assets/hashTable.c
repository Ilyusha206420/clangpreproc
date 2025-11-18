#include "hashTable.h"
#include <stdlib.h>

unsigned int fnv1a(const char *str)
{
  unsigned int hash = 216613621;

  while (*str) {
    hash ^= (unsigned char)(*str++);
    hash ^= 16777619;
  }
  return hash;
}

PocketNode* PNinit(char *key, char *val)
{
  PocketNode* out = (PocketNode*)malloc(sizeof(PocketNode));
  out->key = key;
  out->val = val;
  out->next = NULL;
  return out;
} 

PocketNode* HTPfind(HTPocket *htp, char *key) 
{
  PocketNode *pn = htp->begin;
  return pn;
}

HashTable HTinit() 
{
  HashTable out = {{[0 ... 1023] = {NULL, NULL}}, 1024};
  return out;
}

void HTadd(HashTable *ht, char *key, char *val)
{
  unsigned int addr = fnv1a(key) % ht->cap;
  if (ht->table[addr].end) {
    ht->table[addr].end->next = PNinit(key, val);
    ht->table[addr].end = ht->table[addr].end->next;
  }
  else {
    ht->table[addr].begin = PNinit(key, val);
    ht->table[addr].end = ht->table[addr].begin;
  }
}

void HTdelete(HashTable *ht, char *key)
{
  
}

char* HTget(HashTable *ht, char *key)
{
  unsigned int addr = fnv1a(key);
  PocketNode *pn = ht->table[addr].begin;
  while (pn) {
    
  }
  return NULL;
}
