#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
char info;
Node *next;
};

struct LinkedList
{
Node *head;
};

void Push(Node *&node, char elem)
{
Node *p = new Node;
p->info = elem;
p->next = NULL;
node->next = p;
node = p;
};

void Dispose(Node *&node)
{
while(node != NULL){
Node *p = node;
node = node->next;
delete(p);
}
};

char Pop(Node *&node)
{
char c = node->info;
node = node->next;
return c;
};

int main()
{
fstream in("input.txt");
ofstream out("output.txt");
int l = 0,i = 0;
char ch;
Node *p_t = new Node;
p_t->next = NULL;
LinkedList v,t;
t.head = p_t; v.head = NULL;
while(!in.eof()){
ch = in.get();
if((ch == ' ') || (ch == '\n') || (ch == EOF)){
if(i > l){
l = i;
Dispose(v.head);
v.head = t.head;
} else {
Dispose(t.head);
}
p_t = new Node;
p_t->next = NULL;
t.head = p_t;
i = -1;
} else Push(p_t,ch);
i++;
}
out « l « endl;
for(i = 0; i < l; i++){
ch = Pop(v.head->next);
out«ch;
}
Dispose(t.head);
Dispose(v.head);
return 0;
}
#include "LinkedList.h"
#include <iostream>

void Push(Node *&node, char c)
{
Node *p = new Node;
p->info = c;
p->next = NULL;
node->next = p;
node = node->next;
};

bool Сoincide(Node *node_1, Node *node_2)
{
bool a = true;
while((a) && (node_1 != NULL) && (node_2 != NULL)){
if (node_1->info != node_2->info) a = false;
node_1 = node_1->next; node_2 = node_2->next;
}
if((a) && (node_1 == NULL) && (node_2 == NULL)) a = true;
else a = false;
return a;
};

char Pop(Node *&node)
{
char c;
c = node->info;
node = node->next;
return c;
};

void Dispose(Node *&node)
{
while(node != NULL){
Node *p = node;
node = node->next;
delete(p);
}
};