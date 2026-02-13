// ���� ���� C�ڷᱸ��(�ֿ���, ���� ���ǻ�, 2024)
// �������� ch07/TreeTraversal.c


//--------------------------------------------------------------------
// �ڵ� 7.2 ���� Ʈ���� ��ȸ


#include <stdio.h>
#include <stdlib.h>
typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

#define VisitNode(n) (printf("[%c] ", (n)->data))
void preorder(TNode* n)
{
    if (n != NULL) {
        VisitNode(n);
        preorder(n->left);
        preorder(n->right);
    }
}
//--------------------------------------------------------------------
// �ڵ� 7.3 ��ø�� ��ȣ ǥ���� ���� ������ȸ �Լ�
/*
void preorder(TNode* n)
{
    if (n != NULL) {
        printf("( ");
        printf("%c ", n->data);
        // VisitNode(n);
        preorder(n->left);
        preorder(n->right);
        printf(")");
    }
}
*/

void inorder(TNode* n)
{
    if (n != NULL) {
        inorder(n->left);
        VisitNode(n);
        inorder(n->right);
    }
}
void postorder(TNode* n)
{
    if (n != NULL) {
        postorder(n->left);
        postorder(n->right);
        VisitNode(n);
    }
}

#define MAX_SIZE 100            // ť�� ���� �迭�� ũ��
typedef TNode* Element;         // ť ����� �ڷ���
#include "CircularQueue.h"      // ���� ť �ڵ� ����

void levelorder(TNode* root)
{
    if (root != NULL) {
        init_queue();
        enqueue(root);          // ��Ʈ ��忡�� ����
        while (!is_empty()) {   // ť�� ������ �ƴϸ� �ݺ�
            TNode* n = dequeue();
            if (n != NULL) {
                VisitNode(n);
                enqueue(n->left);
                enqueue(n->right);
            }
        }
    }
}

void main()
{
    TNode d = { 'D', NULL, NULL };
    TNode e = { 'E', NULL, NULL };
    TNode b = { 'B', &d, &e };
    TNode f = { 'F', NULL, NULL };
    TNode c = { 'C', &f, NULL };
    TNode a = { 'A', &b, &c };
    TNode* root = &a;

    printf("\n   In-Order : ");
    inorder(root);
    printf("\n  Pre-Order : ");
    preorder(root);
    printf("\n Post-Order : ");
    postorder(root);
    printf("\nLevel-Order : ");
    levelorder(root);
}
