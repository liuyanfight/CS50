#include <stdio.h> 
#include <stdlib.h> 
//#include <windows.h> 
//#include <queue> 
//#include <stack> 
#define NOT ! 
#define INF 1000000 
#define HashTableSize 362880 
using namespace std; 

typedef struct maps 
{ 
    int detail[3][3]; 
    int hx;                // 实际已经花费 
    int fx;                // 预计花费（fx） = 实际已经花费（hx） + 预计剩余花费（gx） 
    int parent;            // 记录父节点在hash表中的位置 
    int myindex;        // 记录自己节点在hash表中的位置 
    int x, y;                // 记录 空格（0）的坐标 
   // bool operator < (const maps&  a)  ; 

}Map,*PMap; 

/*** 重载 == 运算符*****/ 
bool operator < (const maps& a, const maps& b)  
{ 
  return a.fx > b.fx ;  
} 

Map   org;                    //  初始状态 
Map   result; 
int   end[9][2] ;            // 目的状态 
int   BestAnswer;           // 目前最好结果的代价 
     
PMap  HashTable[HashTableSize]={NULL};        //hash表 
bool  FlageNew;                                //标志是否是新状态 

short const derection[4][2] ={ { 0 , -1 } , { -1 , 0 } , { 0, 1 } , {1, 0 } } ;  // 可移动的四个方向 

/** 
 * 
 * 评估函数 h(x) ： 计算每个位置到离它目标位置的和。 
 * 
 **/ 

int evaluate_hx(int a[3][3])   
{ 
    int hx =0 ; 
    int temp ;  

    for(int i =0 ; i < 3; i ++ ) 
        for(int j =0 ; j< 3 ;j ++ ) 
         { 
            if(a[i][j] ==0) continue ;  
            temp = i - end[ a[i][j] ][0] ;  
            if(temp < 0 ) temp = -temp ;  
            hx += temp ;  
            temp = j  - end[ a[i][j] ][1] ;  
            if(temp < 0 ) temp = - temp ;  
            hx += temp ;  
        } 

    return hx ;  
} 


/** 
 * 
 *    八数码的输入（在这里不做任何输入检查，均认为输入数据是正确的） 
 * 
 **/ 
void input() 
{ 
    int i,j; 
    int sum; 
    for(i = 0 ; i < 9 ; i ++ ) 
    { 
        scanf("%1d", *org.detail + i ); 
        if(0 == *(*org.detail + i) ) 
        { 
            org.x = i / 3; 
            org.y = i % 3; 
        } 
    } 

    for(i = 0 ; i < 9 ; i ++ )                //计算逆序 
    { 
        if( 0 == *(*org.detail + i) )  
            continue; 

        for(j = 0 ; j < i;  j ++ ) 
            if( 0 != *(*org.detail+j) && *(*org.detail + j) < *(*org.detail + i) )  
            { 
                sum ++;  
            } 
    } 
    org.hx = 0 ; 
    org.fx = evaluate_hx( org.detail ); 

    if( sum%2 == 0 )        // 保存各个数字的坐标。 
    { 
        end[0][0] = 2 , end[0][1] = 2 ; 
        end[1][0] = 0 , end[1][1] = 0 ; end[2][0] = 0 , end[2][1] = 1 ;  
        end[3][0] = 0 , end[3][1] = 2 ; end[4][0] = 1 , end[4][1] = 0 ;  
        end[5][0] = 1 , end[5][1] = 1 ; end[6][0] = 1 , end[6][1] = 2 ;  
        end[7][0] = 2 , end[7][1] = 0 ; end[8][0] = 2 , end[8][1] = 1 ;  
    } 
    else 
    { 
        end[0][0] = 1 , end[0][1] = 1 ; 
        end[1][0] = 0 , end[1][1] = 0 ; end[2][0] = 0 , end[2][1] = 1 ;  
        end[3][0] = 0 , end[3][1] = 2 ; end[4][0] = 1 , end[4][1] = 2 ;  
        end[5][0] = 2 , end[5][1] = 2 ; end[6][0] = 2 , end[6][1] = 1 ;  
        end[7][0] = 2 , end[7][1] = 0 ; end[8][0] = 1 , end[8][1] = 0 ;  
    } 

    return; 
}
/** 
 * 
 *检测两个状态是否一样 
 * 
 **/ 
inline bool IsEqual(Map a , Map b) 
{ 
    return 0 == memcmp((const void *)(*a.detail),(const void *)(*b.detail),36); 
} 

/** 
 * 
 * hash值的计算 
 * 
**/ 
int HashValue(Map a)    
{ 
   int count  ;  
   int i , j ; 
   int value =0 ; 
   static int pv[9]={1,1,2,6,24,120,720,5040,40320}; 
   for(i = 0 ; i < 9 ; i ++ ) 
   { 
       for(j = 0, count =0 ; j < i ; j ++ ) 
       { 
            if( *(*a.detail+i) < *(*a.detail+j) )  
            { 
                count ++; 
            } 
       } 
       value += pv[i]*count; 
   } 
    return value; 
} 

/** 
 * 
 *状态插入到hash表中。返回的是插入到的hash表中对应的下标值 
 * 
 **/ 
int InsertHashTable(Map a , int parent) 
{ 
    int index = HashValue( a ); 
    if(NULL == HashTable[index])  //如果为TURE，那么说明hash表中不存在该状态，应该插入到hash表中 
    { 
        a.parent = parent; 
         HashTable[index] = new Map; 
        *HashTable[index] = a; 
        FlageNew = true; 
    } 
    else 
    { 
        FlageNew = false; 
    } 
    return index; 
} 

void Axin() 
{ 
    Map node; 
    priority_queue<Map> Queue; 
    org.myindex = InsertHashTable( org , -1 ); 
    Queue.push( org ); 
    while( NOT Queue.empty() ) 
    { 
        node = Queue.top(); 
        Queue.pop(); 

        for(int k =0 ; k < 4; k ++ ) 
         { 
            Map tmp = node; 
            tmp.x = node.x + derection[k][0], 
            tmp.y = node.y + derection[k][1]; 
            if(tmp.x < 0 || tmp.x > 2 || tmp.y <0 || tmp.y >2 )  
            { 
                continue; 
            } 

            tmp.detail[ node.x ][ node.y ] = tmp.detail[ tmp.x ][ tmp.y ];        //移动空格 
            tmp.detail[ tmp.x ][ tmp.y ] = 0 ; 

            int tmpindex = InsertHashTable( tmp , node.myindex ); 

            if( false == FlageNew )        //如果不是新状态的,即以前访问过改节点，不再加入队列中 
            { 
                continue; 
            } 

            tmp.parent = node.myindex; 
            tmp.myindex = tmpindex; 
            tmp.hx = node.hx + 1 ; 
            tmp.fx = tmp.hx + evaluate_hx( tmp.detail ); 
            if( tmp.fx  == tmp.hx )  
            { 
                result = tmp; 
                return ; 
            } 
            Queue.push(tmp); 
        } 
    } 
    return ; 
    } 


/** 
 * 
 * 通过hash表中记录的进行查找路径 
 * 
 **/ 
void FindPath() 
{ 
    Map now; 
    stack<Map> Stack; 
    Stack.push(result); 
    now = result; 
    int count=0; 
    while(now.parent != -1 ) 
    { 
        Stack.push(*HashTable[now.parent]); 
        now = Stack.top(); 
    } 

    printf("共需： %d 步\n",Stack.size()-1); 
    getchar(); 
    while( NOT Stack.empty()) 
    { 
        now = Stack.top(); 
        Stack.pop(); 
        for(int i =0 ; i < 3; i ++ ) 
        { 
            for(int j =0 ; j < 3; j  ++) 
            { 
                printf("%3d",now.detail[i][j]); 
            } 
            printf("\n"); 
        } 
        if(0 != Stack.size() ) 
        { 
            printf("\n    ↓ 第%d步\n",++count); 
            getchar(); 
        } 
    } 
    printf("\nThe End!\n"); 
    return ; 
} 


int main() 
{ 
    input(); 
    long time =GetTickCount(); 
    Axin(); 
    printf("计算用时：%dMS\n",GetTickCount()-time); 
    FindPath(); 
    return 0; 
}

