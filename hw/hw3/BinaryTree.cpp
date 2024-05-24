/*
이진 탐색 트리의 특징 : 왼쪽 자식노드 < 부모 노드  < 오른쪽 자식 노드
    부모 노드보다 왼쪽 자식 노드가 작다.
    부모 노드보다 오른쪽 자식 노드가 크다.
*/
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void insert(node **root, int data); // 루트노드가 root 인 이진검색트리에 데이터 data 를 입력하는 함수 / 각 노드는 동적으로 메모리를 할당하여 구현
void preOrder(node *root); // 밟은 루트 먼저 출력하고 이하 노드 탐색
void inOrder(node *root); // 가장 왼쪽 자식 노드 출력 후 올라가면서 부모 노드 출력 -> 오른쪽 노드 출력
void postOrder(node *root); // 가장 왼쪽 자식 노드 출력 후 부모 노드 출력 전 오른쪽 노드 출력 -> 부모노드 출력 -> 오른쪽으로 가면서 다른 동일 height에 위치한 노드를 이전 방식과 같은 방식으로 출력 -> 부모노드 출력

int size(node *root); // 트리에 포함된 모든 노드의 갯수
int height(node *root); // 깊이 중 최댓값
int sumOfWeight(node *root); // 모든 노드에 저장된 데이터의 합
int maxPathWeight(node *root); // 루트노드부터 단말노드까지의 경로 상의 모든 노드에 저장된 데이터의 합이 가장 큰 합
 
void mirror(node **root); // 루트노드가 root 인 이진검색트리를 미러 이지미가 되도록 노드의 순서를 변환
void destruct(node **root); // 루트노드가 root 인 이진검색트리의 동적으로 메모리 할당된 노드를 해제하여 이진검색트리를 소멸시킴

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        node *root = nullptr; // node 타입의 포인터인 root를 선언하고 nullptr로 초기화(초기에 아무 노드도 없기 때문에 root를 nullptr로 설정)
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            int data;
            cin >> data;
            insert(&root, data);
        }

        cout << size(root) << endl;
        cout << height(root) << endl;
        cout << sumOfWeight(root) << endl;
        cout << maxPathWeight(root) << endl;

        mirror(&root);
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
        destruct(&root);
        cout << (root == nullptr ? 0 : 1) << endl;
    }
    return 0;
}

void insert(node **root, int data) // 이진 트리의 루트 노드를 가리키는 이중 포인터, int data는 삽입될 데이터의 값
{
    if (*root == nullptr)
    {
        *root = new node(); // 새로운 노드를 동적으로 할당하고, *root 포인터를 이 새로운 노드로 업데이트
        (*root)->data = data; // 새로운 노드의 데이터 필드에 data 값을 저장합니다. 이것은 새로운 노드의 데이터를 설정하는 부분임
        (*root)->left = nullptr; // 새로운 노드의 왼쪽과 오른쪽 자식 포인터를 각각 nullptr로 초기화(이것은 새로운 노드가 리프 노드(자식이 없는 노드)라는 것을 의미)
        (*root)->right = nullptr;
    }
    else if (data < (*root)->data) // 현재 노드가 비어있지 않고, data가 현재 노드의 데이터 값보다 작을 때, 왼쪽 서브트리로 이동해야 함을 의미
    {
        insert(&(*root)->left, data); // 따라서 왼쪽 서브트리에 노드를 추가하기 위해 insert 함수를 재귀적으로 호출하고, 현재 노드의 왼쪽 자식 포인터에 대한 주소(&(*root)->left)를 전달
    }
    else // 위의 두 조건을 만족하지 않는 경우, data가 현재 노드의 데이터 값보다 크거나 같으므로 오른쪽 서브트리로 이동해야 함을 의미
    {
        insert(&(*root)->right, data); // data 값을 오른쪽 서브트리에 추가하기 위해 insert 함수를 재귀적으로 호출
    }
}

void preOrder(node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root)
    {
        postOrder(root->left); // 왼쪽 서브트리를 순회하기 위해 postOrder 함수를 재귀적으로 호출. 이것은 현재 노드의 왼쪽 자식 노드로 이동하는 것을 나타냄
        postOrder(root->right);
        cout << root->data << " "; // 현재 노드의 데이터 값을 출력
    }
}

int size(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}

int height(node *root)
{
    if (root == nullptr)
    {
        return -1; // 단말 노드 다음의 노드의 높이는 -1
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int sumOfWeight(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->data + sumOfWeight(root->left) + sumOfWeight(root->right);
}

int maxPathWeight(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->data + max(maxPathWeight(root->left), maxPathWeight(root->right));
}

void mirror(node **root) // 트리의 모든 노드를 왼쪽 자식 노드와 오른쪽 자식 노드를 교환하며 좌우로 뒤집음
{
    if (*root)
    {
        swap((*root)->left, (*root)->right);
        mirror(&(*root)->left);
        mirror(&(*root)->right);
    }
}

void destruct(node **root)
{
    if (*root != nullptr) // 현재 노드가 존재하는지 검사
    {
        destruct(&(*root)->left); // 왼쪽 서브트리를 파괴하기 위해 destruct 함수를 재귀적으로 호출. 현재 노드의 왼쪽 자식 노드로 이동하는 것을 나타냄
        destruct(&(*root)->right); // 오른쪽 서브트리를 파괴하기 위해 destruct 함수를 재귀적으로 호출. 현재 노드의 오른쪽 자식 노드로 이동하는 것을 나타냄
        delete *root; // 현재 노드의 메모리를 해제, *root는 현재 노드를 가리키는 포인터이며, delete 연산자를 사용하여 현재 노드의 메모리를 해제
        *root = nullptr; // 현재 노드를 파괴하고 난 후, 현재 노드 포인터를 nullptr로 설정
    }
}
