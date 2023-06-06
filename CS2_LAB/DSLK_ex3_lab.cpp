
#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int info;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

void CreateList(List& l);
void NhapList(List& l);
int DemSoPhanTu(List l);
void Split(List l, List& l1, List& l2);
void XuatList(List l);

int main()
{
    List l, l1, l2;
    CreateList(l);
    CreateList(l1);
    CreateList(l2);
    NhapList(l);
    if (DemSoPhanTu(l) == 0)
        cout << "Danh sach rong." << endl;
    else
    {
        cout << "Danh sach vua nhap la: ";
        XuatList(l);
        cout << endl;
        Split(l, l1, l2);
        cout << "Cac so chan trong danh sach la: ";
        XuatList(l1);
        cout << endl;
        cout << "Cac so le trong danh sach la: ";
        XuatList(l2);
        cout << endl;
    }
    return 0;
}


void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

void addTail(List& l, Node* newNode) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = newNode;
    }
    else {
        l.pTail->pNext = newNode;
        l.pTail = newNode;
    }
}

void NhapList(List& l) {
    Node* pointer = l.pHead;
    int num;
    while (1) {
        cin >> num;
        if (num != 0)
        {
            Node* newNode = new Node();
            newNode->info = num;
            newNode->pNext = NULL;
            addTail(l, newNode);
        }
        else {
            if (l.pHead == NULL) {
                cout << "Danh sach rong.";
            }
            return;
        }
    }

}

void XuatList(List l) {
    Node* pointer = l.pHead;
    if (l.pHead != NULL) {
        int index = 0;
        int count = 0;
        cout << "Danh sach vua nhap la: ";

        while (pointer != NULL) {
            //index++;
            cout << pointer->info << " ";
            /*if (checkPrime(pointer->info) == true && (index % 2 != 0)) {
                count++;
            }*/
            pointer = pointer->pNext;
            
            
        }
        cout << endl;
        //cout << "Danh sach co " << count << " so nguyen to o vi tri le.";
    }

}

int DemSoPhanTu(List l) {
    Node* p = l.pHead;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->pNext;
    }
    return count;
}

//void deleteNode(List& l, int x) {
//    if (l.pHead->info == x) {
//        Node* tmp = l.pHead;
//        l.pHead = l.pHead->pNext;
//        delete tmp;
//    }
//    if (l.pTail->info == x) {
//        for (Node* i = l.pHead; i != NULL; i = i->pNext) {
//            if (i->pNext->pNext == NULL) {
//                Node* tmp = l.pTail;
//                l.pTail = i;
//                delete tmp;
//                l.pTail->pNext = NULL;
//            }
//        }
//    }
//    for (Node* i = l.pHead; i != NULL; i = i->pNext) {
//        if (i->pNext->info == x) {
//            Node* tmp = i->pNext;
//            i->pNext = i->pNext->pNext;
//            delete tmp;
//        }
//    }
//}

//void deleteNode(List& l, int x) {
//    Node* prev = NULL;
//    Node* curr = l.pHead;
//    while (curr != NULL) {
//        if (curr->info == x) {
//            if (prev == NULL) {
//                l.pHead = curr->pNext;
//                delete curr;
//                curr = l.pHead;
//            }
//            else {
//                prev->pNext = curr->pNext;
//                if (curr == l.pTail) {
//                    l.pTail = prev;
//                }
//                delete curr;
//                curr = prev->pNext;
//            }
//        }
//        else {
//            prev = curr;
//            curr = curr->pNext;
//        }
//    }
//}

void deleteNode(List& l, int x) {
    Node* prev = NULL;
    Node* curr = l.pHead;
    while (curr != NULL) {
        if (curr->info == x) {
            if (prev == NULL) {
                l.pHead = curr->pNext;
            }
            else {
                prev->pNext = curr->pNext;
            }
            if (curr == l.pTail) {
                l.pTail = prev;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->pNext;
    }
}




//void Split(List l, List& l1, List& l2) {
//    Node* p = l.pHead;
//    while (p != NULL)
//    {
//        if (p->info % 2 == 0) {
//            Node* newNode = new Node();
//            newNode->info = p->info;
//            newNode->pNext = NULL;
//            addTail(l1, newNode);
//            
//            deleteNode(l, p->info);
//        }
//        else if (p->info % 2 != 0)
//        {
//            Node* newNode = new Node();
//            newNode->info = p->info;
//            newNode->pNext = NULL;
//            addTail(l2, newNode);
//            Node* q = l.pHead;
//           
//            deleteNode(l, p->info);
//        }
//        p = p->pNext;
//    }
//}

void Split(List l, List& l1, List& l2) {
    Node* p = l.pHead;
    while (p != NULL) {
        if (p->info % 2 == 0) {
            Node* newNode = new Node();
            newNode->info = p->info;
            newNode->pNext = NULL;
            addTail(l1, newNode);
        }
        else {
            deleteNode(l, p->info);
            Node* newNode = new Node();
            newNode->info = p->info;
            newNode->pNext = NULL;
            addTail(l2, newNode);
        }
        p = l.pHead;
    }
}
