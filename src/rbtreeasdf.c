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

node_t *bst(rbtree *t, key_t key, node_t *new_node){

  // 기준(부모) 노드와 비교했을 때 입력하려는 수가 루트 키값보다 같거나 작으면
    if (key <= new_node -> key){

      // 왼쪽 자식 자리가 빈 경우에는 입력한 노드를 위치시킨다. 
      if (new_node -> left == NULL){
        printf("%d %d ,왼쪽/없음\n" ,t->root->key ,new_node->key);
        return new_node;
      }

      //나머지 경우(left에 이미 자리한 노드가 있는 경우)에는 위의 함수를 반복한다.
      else{
        printf("%d %d , 왼쪽/있음\n",t->root->key,new_node->key);
        return bst(t ,key, new_node -> left); //재귀
      }
    }

    // 기준(부모) 노드와 비교했을 때 입력하려는 수가 루트 키값보다 크면
    else{

      // 왼쪽 자식 자리가 빈 경우에는 입력한 노드를 위치시킨다. 
      if (new_node -> right == NULL){
        printf("%d %d , 오른쪽/없음\n",t->root->key,new_node->key);
        return new_node;//입력한 노드의 자리로 지정
      }

      //나머지 경우(left에 이미 자리한 노드가 있는 경우)에는 위의 함수를 반복한다.
      else{
        printf("%d %d , 오른쪽/있음\n",t->root->key,new_node->key);
        return bst(t ,key, new_node->right);//재귀
      }
    }
}

/**
 * @param t
 * @param key
 * @return 
*/
node_t *rbtree_insert(rbtree *t, const key_t key) {

//   //new_node는 node_t 형의 주소값을 저장하는 변수.
//   node_t *new_node = (node_t *)calloc(1, sizeof(node_t));
  
//   // 삽입시 color는 red
//   new_node -> color = RBTREE_RED;

//   // 삽입시 key는 삽입된 숫자
//   new_node -> key = key;                                                                       //숫자입력
  
//   if (t -> root == t -> nil){
//     new_node -> color = RBTREE_BLACK;
//     t -> root =new_node;
//     printf("%d, 루트입니다.\n",key);
//   }
//   else {
//     node_t *par;
//     par = bst(key, t->root);
//   }
        

//이진탐색트리에 따라 왼쪽 오른쪽으로 구분 -while / 재귀를 통해 1차 삽입 위치 지정
//      


        //부모가 빨간색이고 나 역시 빨간색인 경우 회전/ 아래와 함께 생각하기
        //부모가 빨간색이고 삼촌이 빨간색인 경우 조부와 부모/삼촌의 색깔을 교환하고 부모의 기준에서 다시 색깔과 위치를 조정한다.
 
  

  // while문으로 case 3 확인
  

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