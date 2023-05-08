#include "rbtree.h"

#include <stdlib.h>

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

node_t *rbtree_insert(rbtree *t, const key_t key) {
  
  // node_t;
  // //new_node는 node_t 형의 주소값을 저장하는 변수.

  // node_t *new_node = (node_t *)calloc(1, sizeof(node_t));
  // // 삽입시 color는 red
  // new_node -> color = RBTREE_RED;
  // // 삽입시 key는 삽입된 숫자
  // new_node -> key =  ;                                                                       //숫자입력

  // if (t -> root == t -> nil){

  // }

  // // while문으로 case 3 확인
  

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
