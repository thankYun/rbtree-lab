#include "rbtree.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * 새로운 RB tree를 만든다.
 * @return p rbtree 형의 주소값을 반환한다.
*/
rbtree *new_rbtree(void) {
  // p는 rbtree형의 주소값을 저장하는 변수.
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // nilNode는 node_t형의 주소값을 저장하는 변수.
  node_t *nil_node = (node_t *)calloc(1, sizeof(node_t));

  // nilNode의 색깔을 정의한다.
  nil_node -> color = RBTREE_BLACK;

  // 트리 p의 nil에 nilNode 할당. 센티넬 노드.
  p -> nil = nil_node;
  // 트리 p의 root에 nilNode 할당. 센티넬 노드.
  p -> root = nil_node;

  return p;
}

/**
 * RB tree를 삭제한다.
 * @param t *t 삭제할 트리의 주소값
 * @return 아무것도 반환하지 않는다.
*/
void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

/**
 * 이진 탐색 트리의 삽입 규칙을 지키면서 insert
 * @param n *n 해당 노드의 주소값
 * @param key 새로운 노드의 key
 * @return
*/
node_t *path_find(node_t *n, key_t key) {
  if (key <= n -> key) {
    // 새로운 노드의 키값이 현재 노드의 키값보다 작으면? 왼쪽으로 들어감.
    printf("%d %d 왼\n",n->key, key);
    return (n -> left == NULL) ? n : path_find(n -> left, key); 
  }else {
    // 새로운 노드의 키값이 현재 노드의 키값보다 크면? 오른쪽으로 들어감.
    printf("%d %d 오른쪽\n",n->key, key);
    return (n -> right == NULL) ? n : path_find(n -> right, key);
  }
}

/**
 * RB tree에 노드를 추가한다.
 * @param t 
 * @param key
 * @return
 *  
*/
node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *new_node = (node_t *)calloc(1, sizeof(node_t));
  new_node -> color = RBTREE_RED;
  new_node -> key = key;

  if (t -> root == t -> nil) {
    // 루트 노드가 nil 노드일 경우 
    new_node -> color = RBTREE_BLACK;
    t -> root = new_node;
  }else {
    // 루트 노드가 nil 노드가 아닌 경우 즉, new_node가 첫 노드가 아닌 경우
    // 이진탐색트리의 규칙을 지키면서 삽입.
    // 트리의 키 값을 비교해 가면서 아래로 타고 들어감.
    node_t *final_node;

    final_node = path_find(t -> root, key);

    // printf("%d\n", final_node -> key);
    // printf("\n");

    if (final_node -> key > key) {
      final_node -> left = new_node;
    }else {
      final_node -> right = new_node;
    }

    new_node -> parent = final_node;

    // RED는 중복될 수 없다. -> restructuring 함수 호출.
    // insert된 노드의 부모 노드가 red일 때
  };

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

// node_t 형의 주소값을 반환한다.
node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

// node_t 형의 주소값을 반환한다.
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

int main(){
  rbtree *tree;
  tree = new_rbtree();

  rbtree_insert(tree,10);
  rbtree_insert(tree,15);
  rbtree_insert(tree,5);
  rbtree_insert(tree,2);
  rbtree_insert(tree,29);
  rbtree_insert(tree,16);
  rbtree_insert(tree,3);
  return 0;
}