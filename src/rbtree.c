#include "rbtree.h"
#include <stdlib.h>
#include <stdio.h>


rbtree *new_rbtree(void) {

  // p는 rbtree형의 주소값을 저장하는 변수.
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));

  // nilNode는 node_t형의 주소값을 저장하는 변수.
  node_t *nil_node = (node_t *)calloc(1, sizeof(node_t));

  // nilNode의 색깔을 정의한다.
  nil_node -> color = RBTREE_BLACK;

  // 트리 p의 nil에 nilNode 할당. 센
  p -> nil = nil_node;
  
  // 트리 p의 root에 nilNode 할당. 센티넬 노드.
  p -> root = nil_node;

  return p;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}


/**
 * 
 * @param t rbtree의 정보를 통해 정렬 후 맨 위의 노드가 루트 노드인지 판단
 * @param x 기준이 될 노드
*/
void rotate_left(rbtree *t, node_t *x){
  node_t*y = x->right;
  x->right = y->left;   // yleft에 있는 수는 x와 y 사이의 수이다. >x right로 변경 가능하다.
  if(y -> left != t -> nil){  //yleft가 nil이 아니었다면 yleft에 있는 parent값도 변경해주어야 한다.
    y -> left -> parent = x; 
    }
  y -> parent = x -> parent;  //기존 x 의 부모를 y의 부모로 설정한다.

  if(x->parent == t->nil){  //만약 x가 루트였다면 y를 루트로 설정한다.
    t->root = y;
  }
  else if(x==x->parent->left){  // 만약 x가 누군가의 왼쪽 자식이었다면
    x->parent->left=y;  //누군가의 왼쪽 자식을 y로 대체한다.
  }
  else{ //만약 x가 오른쪽 자식이었다면
    x->parent->right=y;    //누군가의 오른쪽 자식을 x로 대체한다.
  }
  y->right=x;
  x->parent=y;
}

void rotate_right(rbtree *t, node_t *x){
  node_t *y = x->left;
  x->left = y->right;   // yleft에 있는 수는 x와 y 사이의 수이다. >x right로 변경 가능하다.
  if(y -> right != t -> nil){  //yleft가 nil이 아니었다면 yleft에 있는 parent값도 변경해주어야 한다.
    y -> right -> parent = x; 
    }
  y -> parent = x -> parent;  //기존 x 의 부모를 y의 부모로 설정한다.

  if(x->parent == t->nil){  //만약 x가 루트였다면 y를 루트로 설정한다.
    t->root = y;
  }
  else if(x==x->parent->left){  // 만약 x가 누군가의 왼쪽 자식이었다면
    x->parent->left=y;  //누군가의 왼쪽 자식을 y로 대체한다.
  }
  else{ //만약 x가 오른쪽 자식이었다면
    x->parent->right=y;    //누군가의 오른쪽 자식을 x로 대체한다.
  }
  y->left=x;
  x->parent=y;
}

void rb_Fix(rbtree*t, node_t*z){
  while (z->parent->color == RBTREE_RED)
  {
    if (z->parent == z->parent->parent->left){
      node_t*y=z->parent->parent->right;
      if(y->color == RBTREE_RED){
        z->parent->color=RBTREE_BLACK;
        y->color=RBTREE_BLACK;
        z->parent->parent->color=RBTREE_RED;
        z=z->parent->parent;
      }
      else {
        if(z==z->parent->right){
          z=z->parent;
          rotate_left(t,z);
        }
        z->parent->color=RBTREE_BLACK;
        z->parent->parent->color=RBTREE_RED;
        rotate_right(t,z->parent->parent);
      }
    }
    else{
      node_t *y = z->parent->parent->left;
      if(y->color==RBTREE_RED){
        z->parent->color=RBTREE_BLACK;
        y->color=RBTREE_BLACK;
        z->parent->parent->color=RBTREE_RED;
        z=z->parent->parent;
      }
      else {
        if(z==z->parent->left){
          z=z->parent;
          rotate_right(t,z);
        }
        z->parent->color=RBTREE_BLACK;
        z->parent->parent->color=RBTREE_RED;
        rotate_left(t,z->parent->parent);
      }
    }
  }
  t->root->color=RBTREE_BLACK;
}


/**
 * @param t
 * @param key
 * @return 
*/
node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *z = (node_t *)calloc(1, sizeof(node_t)); // 새 노드 생성 및 동적 할당
  node_t *y = t->nil;
  node_t *x = t->root;
  while(x != t->nil){
    y=x;
    if (key < x->key){
      x=x->left;
    }
    else{
      x=x->right;
    }
  }
  z->parent=y;
  if (y==t->nil){
    t->root=z;
  }
  else if(key < y->key){
    y->left=z;
  }
  else{
    y->right=z;
  }
  z->key=key;
  z->left=t->nil;
  z->right=t->nil;
  z->color=RBTREE_RED;
  rb_Fix(t,z);
  printf("%d, 삽입 완료!\n",key);
  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}
  
node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}

// int main() {
//   rbtree*tree;
//   tree=new_rbtree();
//   rbtree_insert(tree,10);
//   rbtree_insert(tree,15);
//   rbtree_insert(tree,5);
//   rbtree_insert(tree,2);
//   rbtree_insert(tree,29);
//   rbtree_insert(tree,16);
//   rbtree_insert(tree,3);
// }