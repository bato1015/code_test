#include<iostream>

//リスト構造体
struct List{
    int key;
    List *pre;
    List *next;
};

List *pre_list;//ポインタ
//リスト追加
void list_add(int val){
    List *s;
    s= new List;
    s->key=val;
    s->next=pre_list->next;
    pre_list->next->pre=s;
    pre_list->next=s;
    s->pre=pre_list;
}

//リストの初期化
void init_list(){
    pre_list=new List;
    pre_list->pre=pre_list;
    pre_list->next=pre_list;
}


//リストの書くやつ
void print_list(){
    int cnt=0;
    List *current=pre_list->pre;
    while(current!=pre_list){
        if(cnt++>0)
        std::cout<<" ";
        std::cout<<current->key;
        current=current->pre;
    }
    std::cout<<std::endl;
}


/*void print_list1(){
    int cnt=0;
    List *current=pre_list->next;
    while(current!=pre_list){
        if(cnt++>0)
        std::cout<<" ";
        std::cout<<current->key;
        current=current->next;
    }
    std::cout<<std::endl;
}*/

 void delete_node(List *node) {
    //if (node == pre_list) return;  // nodeが番兵の時は何もしない
    // リンクつなぎ変え
    node->pre->next = node->next;
    node->next->pre = node->pre;
    delete node;  // メモリ解放
  }

void delate_all(int N){
    for(int i=0;i<N;i++){
        delete_node(pre_list->pre);
    }
    delete_node(pre_list);
}

//問題点としてnewに対してdeletaが適切におこなえているかわからない
//delate_all1ではwhileがこ案ダンプする。
void delate_all1(){
    while(pre_list->pre==pre_list)
        delete_node(pre_list);
}
void int_list_se(){
    pre_list=pre_list->pre;
    //pre_list->e
}
int main(){
    init_list();
    int N;
    std::cout<<"入力数:";
    std::cin>>N;
    for(int i=0;i<N;i++){
        int w;
        std::cout<<i+1<<":";
        std::cin>>w;
        list_add(w);
    }

    print_list();
    delate_all(N);
delate_all1();
    print_list();
    return 0;
}