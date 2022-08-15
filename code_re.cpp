#include<iostream>

int a=0,b=0;
class Sample{
    private:
        struct List{
            int key;
            List *pre;
            List *next;
        };
        List *pre_list;//ポインタ
        List*dummy;
    public:
        Sample(){
            pre_list=new List;
            pre_list->pre=pre_list;
            pre_list->next=nullptr;
            b++;
        }
        ~Sample(){
            delate_all1();
            delete_node(pre_list);
            std::cout<<a<<b;
        }

        int delate_all1(){
            if(pre_list->next==nullptr){
                return 0;
            }
            delete_node(pre_list->next);
            delate_all1();
        }

        //リスト追加
        void list_add(int val){
            List *s;
            s= new List;
            s->key=val;
            s->next=pre_list->next;
            if(pre_list->next!=nullptr)
                pre_list->next->pre=s; //nullptrでは前後参照ができないから
            pre_list->next=s;
            s->pre=pre_list;
            b++;
        }

         void delete_node(List *node) {
            if (node->next != nullptr){
            // リンクつなぎ変え
            node->pre->next = node->next;
            node->next->pre = node->pre;
            }else{
                pre_list->next=nullptr;

            }
            delete node;  // メモリ解放
            a++;
        }
        

        //リストの書くやつ
        int print_list1(){
            static int cnt=0;
            static List *current=serch_mattan();
            if(current==pre_list){
                std::cout<<std::endl;
                return 0;
            }
            if(cnt++>0)
                std::cout<<" ";
            std::cout<<current->key;
            current=current->pre;
            print_list1();
            //std::cout<<serch_mattan();
        }

        List *serch_mattan(){
            static List *current=pre_list;
            if(current->next==nullptr)
                return current;
            current=current->next;
            serch_mattan();
        }
};

int main(){
    Sample node;
    int N;
    std::cout<<"入力数:";
    std::cin>>N;
    for(int i=0;i<N;i++){
        int w;
        std::cout<<i+1<<":";
        std::cin>>w;
        node.list_add(w);
    }

    node.print_list1();
    return 0;
}