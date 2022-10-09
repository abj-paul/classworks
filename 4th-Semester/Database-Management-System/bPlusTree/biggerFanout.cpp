#include<bits/stdc++.h>
using namespace std;


int MAX,n; //number of child;
struct Node{
  int size;
  Node *parent,*next;
  string *key,*data;
  bool lf;
  Node **point;
} *root;


Node* createNode();
void insertValueAtPoint(Node *parent,string value,Node *right);
void insertInternalNode(Node *parent,string value,Node *left,Node *right);
void insertLeaf(string key,string data);
Node *findLeaf(Node *tempRoot,string key);

int main(void){
  cout << "Order of Tree: ";
  cin >> n;
  MAX=n;

  clock_t start = clock();
  root = createNode();
  string key,data,searchKey;
  ifstream ifile;
  ifile.open("dictionary.txt");
  if(!ifile) return 0;
  while(ifile>>key)
    {
      getline(ifile,data);
      insertLeaf(key,data);
    }
  clock_t end = clock();
  cout << "Time taken to build Tree: " << (float)(end-start)/CLOCKS_PER_SEC << endl;

  int i;
  cout<<"Enter word: ";
  while(cin>>searchKey){       
      start = clock();
    	 Node* leaf= findLeaf(root,searchKey);
    	 for(i=0; i<leaf->size; i++) if(searchKey==leaf->key[i]) break;
    	 if(i==leaf->size) cout<<"No such word!\n";
    	 else cout<<searchKey<<" "<<leaf->data[i]<<endl;
      end = clock();
         cout << "Time taken to search: " << (float)(end-start)/CLOCKS_PER_SEC << endl;
    	 cout<<"Enter word: ";
    }
}

Node* createNode(){
    Node *m=new Node();

    m->point = new Node *[n+1];
    m->key=new string[n];
    m->data=new string[n];

    m->size = 0;
    m->parent = NULL;
    m->next = NULL;
    m->lf = true;
    return m;
}
Node *findLeaf(Node *tempRoot,string key){
    while(tempRoot->lf==false)
    {
        int i;
        for(i=0; i<tempRoot->size; i++) if(key<tempRoot->key[i]) break;
        tempRoot = tempRoot->point[i];
    }
    return tempRoot;
}

void insertValueAtPoint(Node *parent,string value,Node *right){
    int i=parent->size-1;
    for(;i>=0; i--)
    {
        if(parent->key[i]<=value) break;
        else
        {
            parent->key[i+1] = parent->key[i];
            parent->point[i+2] = parent->point[i+1];
        }
    }
    parent->key[i+1] = value;
    parent->point[i+2] = right;
    parent->size++;
}

void insertInternalNode(Node *parent,string value,Node *left,Node *right){
    if(parent==NULL){
        parent = createNode();
        parent->key[0] = value;
        parent->point[0] = left;
        parent->point[1] = right;
        parent->size++;
        parent->lf = false;
        root = parent;
        left->parent = parent;
        right->parent = parent;
        return;
    }
    right->parent = parent;
    insertValueAtPoint(parent,value,right);
    if(parent->size==MAX)
    {
        Node *splitNode = createNode();
        splitNode->lf = false;
        int j=0;
        for(int i=parent->size-(n-1)/2;i<MAX; i++)
        {
            splitNode->key[j] = parent->key[i];
            if(j==0)
            {
                splitNode->point[0] = parent->point[i];
                splitNode->point[0]->parent = splitNode;
            }
            splitNode->point[j+1] = parent->point[i+1];
            splitNode->point[j+1]->parent = splitNode;
            j++;
        }
        parent->size-=(n-1)/2+1;
        splitNode->size = (n-1)/2;
        insertInternalNode(parent->parent,parent->key[parent->size],parent,splitNode);
    }

}

void insertLeaf(string key,string data){
    Node *leaf = findLeaf(root,key);
    int i= leaf->size-1;
    if(i>-1) {
    for(; i>=0; i--)
    {
    	if(key<leaf->key[i])
    	{
    		leaf->key[i+1] = leaf->key[i];
    		leaf->data[i+1] = leaf->data[i];
    	}
    	else break;
    }
    }
    leaf->key[i+1] = key;
    leaf->data[i+1] = data;
    leaf->size++;

    if(leaf->size==MAX){
        Node *splitNode = createNode();
        int j=0;
        for(int i=leaf->size-n/2;i<MAX; i++){
            splitNode->key[j] = leaf->key[i];
            splitNode->data[j] = leaf->data[i];
            j++;
        }
        leaf->size-=n/2;
        splitNode->size = n/2;
        splitNode->next = leaf->next;
        leaf->next = splitNode;
        insertInternalNode(leaf->parent,splitNode->key[0],leaf,splitNode);
    }
}


