#include <string.h>
#include <malloc.h>
 
typedef struct Student
{
    char name[20];
    int score;
    struct Stu *next;
}Stu;
 
int count_nodes_of_a_list(Stu * list)
{
    Stu * tmp = list;
    int count = 0;
    while(tmp){
        count++;
        tmp = tmp->next;
    }
    printf("%d nodes in total\n",count);
    return count;
}
 
void node_print(Stu * node)
{
    printf("%s-->%d\n",node->name,node->score);
}
 
Stu * make_a_list(Stu *head, Stu* tmp)
{
    if(tmp != NULL){
        tmp->next = head;
        head = tmp;
    }
    return head;
}
 
Stu * up(Stu *head,Stu *tmp)
{
    if(head->score == 0){
        return tmp;
    }else if((head->score > tmp->score) || (head->score == tmp->score)){
        tmp->next = head;
        return tmp;
    }else{
        Stu *pre, *cur = head;
        while(cur && (cur->score< tmp->score || cur->score==tmp->score)){
           pre = cur;
           cur = cur->next;
        }
        if(cur == NULL){
            pre->next = tmp;
        }else{
            tmp->next = cur;
            pre->next = tmp;
        }
 
        return head;
    }
}
 
Stu * down(Stu *head,Stu *tmp)
{
    if(head->score == 0){
        return tmp;
    }else if(head->score < tmp->score){
        tmp->next = head;
        return tmp;
    }else{
        Stu *pre, *cur = head;
        while(cur && ((cur->score > tmp->score) || (cur->score==tmp->score))){
           pre = cur;
           cur = cur->next;
        }
        if(cur == NULL){
            pre->next = tmp;
        }else{
            tmp->next = cur;
            pre->next = tmp;
        }
        return head;
    }
}
 
int main()
{
        printf("**** Pro-1 ****\n");
 
        printf("please input the number of students to be sorted by scores \n");
        int num_of_stu = 0;
        scanf("%d",&num_of_stu);
 
        printf("please input 0 or 1, 0 means down and 1 up \n");
        int up_or_down = -1;
        scanf("%d",&up_or_down);
 
        if(!(num_of_stu>0 && (up_or_down==0 || up_or_down==1))){
            printf("invalid input\n");
            return -1;
        }
 
        Stu *head = (Stu *)malloc(sizeof(Stu));
        head->next = NULL;
        head->score = 0;
//        node_print(head);
 
        for(int i=1;i<=num_of_stu;i++){
            Stu *tmp_node = (Stu *)malloc(sizeof(Stu));
//            printf("input num %d name:\n",i);
//            scanf("%s",tmp_node->name);
//            printf("input num %d score:\n",i);
//            scanf("%d",&tmp_node->score);
            printf("please input num%d's name and score\n",i);
            scanf("%s %d",tmp_node->name,&tmp_node->score);
            tmp_node->next = NULL;
 
            if(1==up_or_down){
                head = up(head,tmp_node);
            }
            else if(0==up_or_down){
                head = down(head,tmp_node);
            }
        }
 
        Stu *pre, *cur = head;
        printf("SORTED list:\n");
        while(cur){
            printf("%s ====> %d\n",cur->name,cur->score);
            pre = cur;
            cur = cur->next;
            free(pre);
            pre = NULL;
        }
 
        return 0;
}
