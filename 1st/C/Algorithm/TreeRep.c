// ���� ���� C�ڷᱸ��(�ֿ���, ���� ���ǻ�, 2024)
// �������� ch07/TreeRep.c


//--------------------------------------------------------------------
// �ڵ� 7.1 ���� �Ҵ��� �̿��� Ʈ���� ������ ����


#include <stdio.h>
#include <stdlib.h>

typedef char TElement; // Ʈ�� ��忡 ������ �������� �ڷ���
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;


TNode* create_tree(TElement data, TNode* left, TNode* right)
{
    TNode* n = (TNode*)malloc(sizeof(TNode)); // ��Ʈ ���
    n->data = data;     // ������ ����
    n->left = left;     // ���� ���� Ʈ�� ����
    n->right = right;   // ������ ���� Ʈ�� ����
    return n;           // ��Ʈ ��� ��ȯ
}

void delete_tree(TNode* n)
{
    if (n != NULL) {
        delete_tree(n->left);   // ���� ���� Ʈ�� ����
        delete_tree(n->right);  // ������ ���� Ʈ�� ����
        free(n);                // ��Ʈ ��� ����
    }
}

void main()
{
    /* �׸� 7.17(a) Ʈ�� ���� ���� */
    TNode* d = create_tree('D', NULL, NULL);
    TNode* e = create_tree('E', NULL, NULL);
    TNode* b = create_tree('B', d, e);
    TNode* f = create_tree('F', NULL, NULL);
    TNode* c = create_tree('C', f, NULL);
    TNode* root1 = create_tree('A', b, c);

    /* �׸� 7.17(b) Ʈ�� ���� ���� */
    TNode* D = create_tree('D', NULL, NULL);
    TNode* C = create_tree('C', D, NULL);
    TNode* B = create_tree('B', C, NULL);
    TNode* root2 = create_tree('A', B, NULL);

    /* Ʈ�� ���� ���� */
    delete_tree(root1);
    delete_tree(root2);
}

#ifdef XXX
// ��ȣ�� �̿��� Ʈ�� ���(���� ��ȸ)
void preorder(TNode* n)
{
	if (n != NULL) {
		printf("( ");
		printf("%c ", n->data);
		preorder(n->left);
		preorder(n->right);
		printf(") ");
	}
	else printf(". ");
}
#endif
