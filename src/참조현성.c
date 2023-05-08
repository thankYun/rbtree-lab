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
 * @param t
 * @param key
 * @return 
*/
node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *new_node = (node_t *)calloc(1, sizeof(node_t)); // 새 노드 생성 및 동적 할당

  new_node->key = key; // 새 노드의 값을 입력 값으로 설정
  new_node->color = RBTREE_RED; // 새 노드 삽입 규칙에 의해 새 노드의 색을 레드로 설정
  new_node->left = new_node->right = t->nil; // 새 노드의 왼쪽, 오른쪽 자식을 nil 노드로 설정

  // 새 노드를 삽입할 위치 탐색
  node_t *current = t->root; // 새 노드를 삽입할 위치를 찾기 위해 현재 위치 노드를 루트 노드로 설정한 포인트 변수 생성

  if(current == t->nil) { // 트리가 비어 있는 경우
    t->root = new_node; // 삽입할 새 노드를 루트 노드로 설정
    new_node->color = RBTREE_BLACK; // 레드 블랙 트리 속성 2(루트 노드 색은 블랙) 위반이므로, 새 노드 색 블랙으로 설정
    printf("%d\n", t->root->key);
  }

  while(current != t->nil) { // 트리가 비어있지 않은 경우
    if(key <= current->key) { // 새 노드의 값이 현재 노드의 값보다 작으면, 새 노드를 왼쪽 서브 트리에 삽입하는 경우
      if(current->left == t->nil) { // 현재 위치 노드의 왼쪽 자녀가 nil 노드인 경우
        current->left = new_node; // 현재 위치 노드의 왼쪽 자녀로 새 노드 삽입
        printf("%d\n", current->key);
        break; // 새 노드를 삽입할 위치를 찾았으므로 if문 탈출
      }
      current = current->left; // 현재 위치 노드의 왼쪽 자녀가 nil 노드가 아닌 경우, 현재 위치 노드를 현재 위치 노드의 왼쪽 자녀로 설정
    }
    else { // 새 노드의 값이 현재 노드의 값보다 크면, 새 노드를 오른쪽 서브 트리에 삽입하는 경우
      if(current->right == t->nil) { // 현재 위치 노드의 오른쪽 자녀가 nil 노드인 경우
        current->right = new_node; // 현재 위치 노드의 오른쪽 자녀로 새 노드 삽입
        printf("%d\n", current->key);
        break; // 새 노드를 삽입할 위치를 찾았으므로 if문 탈출
      }
      current = current->right; // 현재 위치 노드의 오른쪽 자녀가 nil 노드가 아닌 경우, 현재 위치 노드를 현재 위치 노드의 오른쪽 자녀로 설정
    }
    new_node->parent = current; // 새 노드의 부모 설정
  }

  // rbtree_insert_fixup(); // 새 노드 삽입 후, 트리 균형 조정

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

int main() {
  rbtree*tree;
  tree=new_rbtree();
  rbtree_insert(tree,10);
  rbtree_insert(tree,15);
  rbtree_insert(tree,5);
  rbtree_insert(tree,2);
  rbtree_insert(tree,29);
  rbtree_insert(tree,16);
  rbtree_insert(tree,3);
}