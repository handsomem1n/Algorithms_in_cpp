// union한 set를 저장할 새로운 배열을 만들지 않아도됨. 왜냐면 기존의 노드에서 그 노드의 pointer만 바뀌기 때문에.

/*
총평 : 이 코드에서 단점은 find함수로, 트리의 height가 커질수록 operation이 느릴 수 있다.
    how to solve ?
        solution 1. weighting(node의 갯수가 smaller to large로 linking하여 balance를 맞춘다.)

*/ 


#include <iostream>
#include <vector>

using namespace std;

struct Data{
    // int value;
    // int pointer_of_value;
    int v;
    int pv;
    int sz;

    // Data(int v, int pv) : value(v), pointer_of_value(pv){}
    Data(int value, int pointer_of_value) : v(value), pv(pointer_of_value) , sz(1) {}
};

int find(vector<Data> &datas, int a) {
    // while (datas[a].v != datas[a].pv) { // 병합하려는 노드의 부모 노드 찾기(자기 자신을 가리키지 않을 때 까지 반복)
    //     // datas[p].v = datas[p].(data[p].pv) // 이거 아님
        
    //     // datas[a].pv = find(datas, datas[a].pv);
    //     // 주목 //
    //     // datas[a].v = datas[datas[a].v].pv; // 가 아님 <- 포인터를 꼬꼬무해야하기때문에.
        
    //     // 주목 //



    // }

    if (datas[a].v != datas[a].pv) {
        datas[a].pv = find(datas, datas[a].pv); // path compression(경로 압축)
    }

    // return datas[p].v; 
    return datas[a].pv; 
    /*
    find 함수에서는 while 루프를 사용하여 datas[p].pointer_of_value가 자기 자신을 가리키지 않을 때까지(즉, 루트를 찾을 때까지) 반복합니다.
    이렇게 해서 찾은 datas[p].pointer_of_value가 그 요소의 루트임. 따라서 // return datas[p].v; //가 아니고, return datas[p].pv이다.
    */
}


bool in_same_set(vector<Data> &datas, int p, int q) {
    /*
    아래의 조건문을 단순화할 수 있다.
    if (find(p) == find(q)) {
        return true;
    }
    else if (find(p) != find(q)){
        return false;
    }
    */
   return find(datas, p) == find(datas, q);
}


void union1(vector<Data> &datas, int p, int q) { /* 'union1(vector<Data> datas, int p, int q)'는 벡터를 값으로 전달하고 있다. 
이렇게 하면 datas의 복사본이 생성되어 함수 내에서 수정해도 원본 datas 벡터에는 영향을 주지 않습니다. datas를 참조로 전달해야 함.
*/ 

    /*
        p,q가 동일 set가 아닐 경우
    */ 
    // if (in_same_set(datas,p,q) == false) {
    //     int root_p = find(datas, p);
    //     int root_q = find(datas, q);
    //     datas[root_p].pv = root_q;
    // }
    int root_p = find(datas, p);
    int root_q = find(datas, q);

    if (root_p != root_q) { // 부모 노드가 다르다면, 즉 다른 세트라면
        // 더 작은 집합을 더 큰 집합에 합침
        if (datas[root_p].sz < datas[root_q].sz) {
            datas[root_p].pv = root_q;
            datas[root_q].sz += datas[root_p].sz;
        } else {
            datas[root_q].pv = root_p;
            datas[root_p].sz += datas[root_q].sz;
        }
    }
}


int main() {
    int n;
    cin >> n;

    vector<Data> datas;

    for (int i = 0 ; i < n ; i++){ 
        int value;
        int pointer_of_value;
        cin >> value >> pointer_of_value;
        datas.push_back(Data(value, pointer_of_value));
    }

    int p, q; // merge할 인덱스
    cin >> p >> q;
    union1(datas, p, q); // union(p,q) : p 를 q에 합침
    for (const Data &data : datas) {
        cout << " union_datas(v) : " << data.v << " union_datas (pv) : " << data.pv << ", Size: " << data.sz << endl; // datas.v, datas.pv가 아님.
    }
    return 0;
    

}

