#include "bt.h"
#include <windows.h>

void BST::SetCursorPosition(int x, int y)
{
    HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(output, pos);
}

void BST::Print(node* node, int x, int y)
{
    if (node == nullptr)
        return;

    SetCursorPosition(x, y);

    cout << node->data;
    Print(node->left, x - (5 / (y + 1)), y + 1);
    Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BST::Insert(node* node) {//��� n�� ���� Ž�� Ʈ���� ������. ���� Ʈ���̸� n�� ��Ʈ�� �ϰ�, �׷��� ������ insertRecur�� ȣ���ؼ� ��带 ����
    if (root == NULL) root = node;
    else InsertRecur(root, node);
}

void BST::InsertRecur(node* root, node* node)
{
    if (GetData(node) == GetData(root))
        return;
    else if (GetData(node) < GetData(root)) {
        if (GetLeftSubTree(root) == NULL)
            MakeLeftSubTree(root, node);
            
        else
            InsertRecur(root->left, node);// ��ĭä���
    }
    else {
        if (GetRightSubTree(root) == NULL)
            MakeRightSubTree(root, node);
        else
            InsertRecur(root->right, node);// ��ĭä���
    }
}

void BST::Delete(int key) {
    if (root == NULL) return;
    node* parent = NULL; // ���� ����� �θ�
    node* nd = root; // ���ٳ��
    while (nd != NULL && GetData(nd) != key) {
        parent = nd;
        nd = (key < GetData(nd)) ? GetLeftSubTree(nd) : GetRightSubTree(nd); // ��ĭä���
    }
    if (nd == NULL) {//���� ��尡 Ʈ���� ����
        cout << "key is not in the tree" << endl;
        return;
    }
    else Delete(parent, nd);
}

void BST::Delete(node* parent, node* nd) {
    //1. �����Ϸ��� ��尡 �ܸ� ����� ���
    if (GetLeftSubTree(nd) == NULL && GetRightSubTree(nd) == NULL) {
        if (parent == NULL) // �����Ϸ��� ��尡 �ٳ���� ��
            root = NULL;
        else {
            if (GetLeftSubTree(parent) == nd)
                MakeLeftSubTree(parent, NULL); // ��ĭä���
            else
                MakeRightSubTree(parent, NULL); // ��ĭä���
        }
    }

    //2. �����Ϸ��� ��尡 �ڽ� 1���� ���
    else if (GetLeftSubTree(nd) == NULL || GetRightSubTree(nd) == NULL) {
        //child�� ������ ����� ������ �ڽ�
        node* child = (GetLeftSubTree(nd) != NULL) ? GetLeftSubTree(nd) : GetRightSubTree(nd);
        //������ ��尡 ��Ʈ�̸� child�� ���ο� ��Ʈ�� ��
        if (nd == root) root = child;
        //�ƴϸ� �θ����� �ڽ����� child�� ����
        else {
            if (GetLeftSubTree(parent) == nd)
                MakeLeftSubTree(parent, child); //��ĭ ä���
            else
                MakeRightSubTree(parent, child); //��ĭ ä���
        }
    }

    //3. �����Ϸ��� ��尡 �ڽ� 2���� ���
    else {
        //�����Ϸ��� ����� ������ ����Ʈ������ ���� ���� ���(�İ� ���,succession)�� Ž��
        // s:�İ��� sp:�İ����� �θ���
        node* sp = nd;
        node* s = GetRightSubTree(nd);
        while (GetLeftSubTree(s) != NULL) { /// ��ĭä���
            sp = s;
            s = GetLeftSubTree(s);
        }
        if (GetLeftSubTree(sp) == s)    // �İ� ����� �θ�� �İ� ����� ������ �ڽ��� ���� ����
            MakeLeftSubTree(sp, GetRightSubTree(s));
        else // �İ� ��尡 ������ ����� �ٷ� ������ �ڽ��� ���
            MakeRightSubTree(sp, GetRightSubTree(s));
        //�İ� ��� ������ ������ ��忡 ����
        SetData(nd, GetData(s));
        delete s;
    }
}
