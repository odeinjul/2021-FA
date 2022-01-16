// EXPR - 3   |  2021.11.20
// Matrix

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

// DEFINATIONS
#define MAX_NUM 50
#define INF 0x3fff
typedef int valType;
typedef char nodeType;
//AdjMArtrix
typedef struct AdjMartrixs{
    int n,e;
    valType map[MAX_NUM][MAX_NUM]; //map
    nodeType node[MAX_NUM];
}AdjMartrix;
int n;
//AdjList
typedef struct ArcNode {
    int index;
    struct ArcNode *next;
    valType info;
}ArcNode;
typedef struct Node{
    nodeType data;
    ArcNode *firstArc, *lastArc;
}VNode, AdjList[MAX_NUM];
typedef struct {
    AdjList nodes;
    int n,e;
}AdjLists;
AdjMartrix G1;
AdjLists G2;
int stack[MAX_NUM+10]={0},visited[MAX_NUM+10]={0},queue[MAX_NUM+10]={0},cnt0=0,cnt=0;
typedef struct MSTNode{
    int u,v;
    valType w;
}MST[MAX_NUM];
MST T;
int dis[MAX_NUM], path[MAX_NUM];
// DEFINATIONS

//FUNCTIONS
void CreateAdjMartrix();
void PrintAdjMartrix();
int  LocateNode_Martrix(char a);
int  LocateNode_List(char a);
void CreateAdjList();
void AddArc(int u, int v, int w);
void PrintAdjList();
void VisitListNode(int index);
void VisitMapNode(int index);
void DFS(char s);
void ClearVisited();
void BFS(char s);
void InitCandidateSet(char s);
int SelectLightSet(int k);
void ModifyCandidateSet(int k, int u);
void PrimMST(char s);
void PrintMST();
void Dijkstra(char s);
void PrintPath();
//FUNCTIONS

int main(){
    CreateAdjMartrix();
    PrintAdjMartrix();
    CreateAdjList();
    PrintAdjList();
    //Create

    char s1,s2;
    cout << "Please enter s1(DFS), s2(BFS)" << endl;
    cin >> s1 >> s2;
    DFS(s1);
    ClearVisited();
    BFS(s2);
    //visit

    cout << "Please enter s(MST)" << endl;
    cin >> s1;
    PrimMST(s1);
    PrintMST();
    //MST

    cout << "Please enter s(DIJKSTRA)" << endl;
    cin >> s1;
    Dijkstra(s1);
    PrintPath();
    return 0;
}

/* SAMPLE
6 9
A B C D E F
A B 1
A D 4
A E 3
B D 4
B E 2
C E 4
C F 5
D E 4
E F 7
*/

//FUNCTIONS - Q1 -CREATE
void CreateAdjMartrix(){
    cin >> G1.n >> G1.e;
    char u,v;
    int w;
    for(int i = 0;i < G1.n; i++){
        cin >> G1.node[i];
    }
    for(int i = 0;i < G1.n; i++){
        for(int j=0;j < G1.n; j++){
            G1.map[i][j] = INF;
            if(i == j)
                G1.map[i][j] = 0;
        }
    }
    for(int i = 0;i < G1.e; i++){
        cin >> u >> v >> w;
        int u0 = LocateNode_Martrix(u), v0 = LocateNode_Martrix(v);
        G1.map[u0][v0] = G1.map[v0][u0] = w;
    }
}
int LocateNode_Martrix(char a){
    for(int i = 0;i < G1.n; i++){
        if(G1.node[i] == a)
            return i;
    }
    cout<<"Error! Node not found!\n";
    return 0;
}
int LocateNode_List(char a){
    for(int i = 0;i < G2.n; i++){
        if(G2.nodes[i].data == a)
            return i;
    }
    cout<<"Error! Node not found!\n";
    return 0;
}
void PrintAdjMartrix(){
    cout<<"---    AdjMartrix    ---"<<endl;
    cout << "/\t";
    for(int i = 0;i < G1.n; i++){
        cout << G1.node[i] << '\t';
    }
    cout<<endl;
    for(int i = 0; i < G1.n; i++){
        cout << G1.node[i] << '\t';
        for(int j = 0; j < G1.n; j++)
            if(G1.map[i][j] == INF)
                cout << "#\t";
            else
                cout << G1.map[i][j] <<'\t';
        cout<<endl;
    }
    cout<<"-----------------------"<<endl;
}
void CreateAdjList(){
    cin >> G2.n >> G2.e;
    char u,v;
    int w;
    for(int i = 0; i < G2.n; i++){
        cin >> G2.nodes[i].data;
    }
    for(int i = 0; i < G2.e; i++){
        cin >> u >> v >> w;
        int u0 = LocateNode_List(u), v0 = LocateNode_List(v);
        AddArc(u0, v0, w); AddArc(v0, u0, w);
    }

}
void AddArc(int u, int v, int w){
    ArcNode *temp = (ArcNode *)malloc(sizeof(ArcNode));
    temp -> index = v;
    temp -> info = w;
    ArcNode *a = G2.nodes[u].firstArc;
    if(a == NULL){
        G2.nodes[u].firstArc = temp;
        G2.nodes[u].lastArc = temp;
    }
    else{
        while(a -> next != NULL)
            a = a -> next;
        a -> next = temp;
        G2.nodes[u].lastArc = temp;
    }
}
void PrintAdjList(){
    cout<<"---     AdjList     ---"<<endl;
    for(int i = 0; i < G2.n; i++){
        cout << G2.nodes[i].data << ":\t";
        ArcNode *temp;
        temp = G2.nodes[i].firstArc;
        if(G2.nodes[i].firstArc == NULL){
            cout<<"#\n";
            break;
        }
        else{
            while(temp != NULL){
                cout << "(" << G2.nodes[temp -> index].data << ", " << temp ->info << ")\t";
                temp = temp -> next;
            }
            cout<<endl;
        }
    }
    cout<<"-----------------------"<<endl;
}

//FUNCTIONS - Q2 - VISIT
void VisitListNode(int index){
    cout << G2.nodes[index].data << ' ';
    return ;
}
void VisitMapNode(int index){
    cout << G1.node[index] <<' ';
    return ;
}
void DFS(char s){
    cout << "DFS - LIST :" << endl;
    VisitListNode(LocateNode_List(s));
    visited[LocateNode_List(s)] = 1;
    stack[++cnt] = LocateNode_List(s);
    ArcNode *p; int temp = 0;
    while(cnt != 0){   
        temp = stack[cnt];
        p = G2.nodes[temp].firstArc;
        while(p != NULL && visited[p -> index] ){
            p = p -> next;
        }
        if(p == NULL){
            stack[cnt] = 0;
            cnt--;
        }
        else{
            visited[p -> index] = 1;
            VisitListNode(p ->index);
            stack[++cnt] = p -> index;
        }
    }
    cout << endl;
}
void ClearVisited(){
    for(int i=0; i <= MAX_NUM; i++){
        visited[i] = 0;
    }
}
void BFS(char s){
    cout << "BFS - MARTRIX :" << endl;
    visited[LocateNode_Martrix(s)] = 1;
    VisitMapNode(LocateNode_Martrix(s));
    stack[++cnt] = LocateNode_Martrix(s);
    int temp  = 0;
    while(cnt-cnt0 != 0){
        temp = stack[cnt];
        for(int i = 0; i < G1.n; i++){
            if(G1.map[temp][i] != INF && !visited[i]){
                stack[++cnt] = i;
                visited[i] = 1; 
                VisitMapNode(i);
            }
        }
        cnt0++;
    }
    cout<<endl;
}

//FUNCTIONS - Q3 - MST
void InitCandidateSet(char s){
    int index = LocateNode_Martrix(s);
    int k = 0;
    for(int i = 0; i < G1.n; i++){
        if(i != index){
            T[k].u = index;
            T[k].v = i;
            T[k++].w = G1.map[index][i];
        }
    }
}
int SelectLightSet(int k){
    int i, min_index = 0, minw = INF;
    for(int i = k; i < G1.n - 1; i++){
        if(T[i].w < minw){
            min_index = i;
            minw = T[i].w;
        }
    }
    if(minw == INF){
        cout << "G is not connected." << endl;
    }
    return min_index;
}
void ModifyCandidateSet(int k, int u){
    int minw;
    for(int i = k; i < G1.n - 1; i++){
        minw = G1.map[u][T[i].v];
        if(minw < T[i].w && u != T[i].v){
            T[i].w = minw;
            T[i].u = u;
        }
    }
}
void PrimMST(char s){
    int k, light_egde_index, v;
    InitCandidateSet(s);
    for(int k = 0; k < G1.n - 1; k++){
        light_egde_index = SelectLightSet(k);
        swap(T[k], T[light_egde_index]);
        //cout << G1.node[T[k].u] << ' ' << G1.node[T[k].v] << ' ' << T[k].w << endl;
        v = T[k].v;
        if(k < G1.n-2) {
            ModifyCandidateSet(k+1, v);
        }
        
    }
}
void PrintMST(){
    cout << "---       MST       ---" << endl;
    for(int i = 0; i < G1.n - 1; i++){
        cout << G1.node[T[i].u] << ' ' << G1.node[T[i].v] << ' ' << T[i].w << endl;
    }
    cout << "---       MST       ---" << endl;
}

//FUNCTIONS - Q4 - PATH
void Dijkstra(char s){
    bool S[G1.n];
    int minn, k;
    int s0 = LocateNode_Martrix(s);
    for(int i = 0; i < G1.n; i++){
        S[i] = 0;
        dis[i] = G1.map[s0][i];
        if(dis[i] < INF) path[i] = s0;
        else path[i] = -1;
    }
    S[s0] = 1; dis[s0] = 0; path[s0] = -1;
    for(int i = 0; i < G1.n - 1; i++){
        minn = INF;
        for(int j = 0; j < G1.n - 1; j++){
            if(!S[j] && dis[j] < minn){
                minn = dis[j]; k = j;
            }
        }
        if(minn == INF) return;
        //cout<<G1.node[k]<<endl;
        S[k] = 1;
        for(int j = 0; j < G1.n; j++){
            //cout<<G1.node[j]<<' ' << dis[j]<<' '<<G1.map[k][j]<<endl;
            if(!S[j] && dis[j] > dis[k] + G1.map[k][j]){
                dis[j] = dis[k] + G1.map[k][j];
                //cout<<G1.node[j]<<' ' << dis[j]<<' '<<G1.map[k][j]<<endl;
                path[j] = k;
            }
        }
    }
}
void PrintPath(){
    cout << "---       PATH      ---" << endl;
    int pre;
    for(int i = 0; i < G1.n; i++){
        cout << G1.node[i] ;
        pre = path[i];
        while(pre != -1){
            cout << " <- ";
            cout << G1.node[pre];
            pre = path[pre];
        }
        cout << " | ";
        cout << "W: " << dis[i] << endl;
    }
    cout << "---       PATH      ---" << endl;
}