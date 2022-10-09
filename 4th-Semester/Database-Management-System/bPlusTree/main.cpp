#include<bits/stdc++.h>
using namespace std;
int FANOUT_VALUE = 3;

class Node {
public:
  bool IS_LEAF;
  string *key;
  string *data;
  int size;
  Node** ptr;
  Node();
};

class BPTree {
  Node* root;
  void updateInternalNode(string,Node*,Node*);
  Node* findParent(Node*,Node*);
  
public:
  BPTree();
  Node* search(string, int* index);
  void insert(string, string);
  void display(Node*);
  Node* getRoot();
};

Node::Node(){
  this->IS_LEAF = true;
  this->size = 0;
  key = new string[FANOUT_VALUE];
  ptr = new Node*[FANOUT_VALUE + 1];
}

BPTree::BPTree(){
  root = NULL;
}

Node* BPTree::search(string x, int* index){
  if(root == NULL){
    cout << "Tree is empty!\n";
    return NULL;
  }else{
    Node* cursor = root;
    
    while (cursor->IS_LEAF == false){
      for(int i = 0;i < cursor->size; i++){
	if(x < cursor->key[i]){
	  cursor = cursor->ptr[i];
	  break;
	}
	
	if(i == cursor->size - 1){
	  cursor = cursor->ptr[i + 1];
	  break;
	}
      }
    }
    for(int i = 0;i< cursor->size; i++){
      if(cursor->key[i] == x){
	cout << "Found\n";
	*index = i;
	return cursor;
      }
    }
    cout << "Not found\n";
    return NULL;
  }
}

void BPTree::insert(string x, string data){
  if(root == NULL){
    root = new Node;
    root->data = new string[FANOUT_VALUE];
    
    root->data[0] = data;
    root->key[0] = x;
    root->IS_LEAF = true;
    root->size = 1;
  }
  else{
    Node* cursor = root;
    Node* parent;
    
    while (cursor->IS_LEAF== false){
      parent = cursor;
      
      for(int i = 0;i < cursor->size;i++){
	if(x < cursor->key[i]){
	  cursor = cursor->ptr[i];
	  break;
	}
	
	if(i == cursor->size - 1){
	  cursor = cursor->ptr[i + 1];
	  break;
	}
      }
    }
    
    if(cursor->size < FANOUT_VALUE){ //ERROR HERE!
      int i = 0;
      while (x > cursor->key[i]
	     && i < cursor->size){
	i++;
      }
      
      for(int j = cursor->size;
	  j > i; j--){
	cursor->key[j]= cursor->key[j - 1];
	cursor->data[j]= cursor->data[j - 1];
      }
      
      cursor->key[i] = x;
      cursor->data[i] = data;
      cursor->size++;
      
      cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
      cursor->ptr[cursor->size - 1] = NULL;
    }
    
    else{
      Node* newLeaf = new Node;
      newLeaf->data = new string[FANOUT_VALUE];
      
      int fix = 1;
      string tempKey[FANOUT_VALUE + 1 + fix];
      string virtualData[FANOUT_VALUE + 1 + fix];
      
      for(int i = 0; i < FANOUT_VALUE; i++){
	tempKey[i]= cursor->key[i];
	virtualData[i]= cursor->data[i];
      }
      int i = 0, j;
      
      while (x > tempKey[i]&& i < FANOUT_VALUE) i++;
      
      for(int j = FANOUT_VALUE + 1;j > i; j--){
	tempKey[j]= tempKey[j - 1];
	virtualData[j]= virtualData[j - 1];
      }

      tempKey[i] = x;
      virtualData[i] = data;
      newLeaf->IS_LEAF = true;
      
      cursor->size = (FANOUT_VALUE + 1) / 2;
      newLeaf->size= FANOUT_VALUE + 1 - (FANOUT_VALUE + 1) / 2;
      
      cursor->ptr[cursor->size]= newLeaf;
      newLeaf->ptr[newLeaf->size]= cursor->ptr[FANOUT_VALUE];
      cursor->ptr[FANOUT_VALUE] = NULL;

      for(i = 0;i < cursor->size; i++){
	cursor->key[i]= tempKey[i];
	cursor->data[i]= virtualData[i];
      }

      for(i = 0, j = cursor->size;i < newLeaf->size;i++, j++){
	newLeaf->key[i]= tempKey[j];
	newLeaf->data[i]= virtualData[j];
      }

      if(cursor == root){
	Node* newRoot = new Node;
	
	// Update rest field of
	// B+ Tree Node
	newRoot->key[0] = newLeaf->key[0];
	newRoot->ptr[0] = cursor;
	newRoot->ptr[1] = newLeaf;
	newRoot->IS_LEAF = false;
	newRoot->size = 1;
	root = newRoot;
      }
      else{
	updateInternalNode(newLeaf->key[0], parent, newLeaf);
      }
    }
  }
}

void BPTree::updateInternalNode(string x,Node* cursor,Node* child){
  if(cursor->size < FANOUT_VALUE){
    int i = 0;
    
    while (x > cursor->key[i] && i < cursor->size){
      i++;
    }
    
    for(int j = cursor->size;j > i; j--){
      cursor->key[j]= cursor->key[j - 1];
    }
    for(int j = cursor->size + 1;j > i + 1; j--){
      cursor->ptr[j]= cursor->ptr[j - 1];
    }
    
    cursor->key[i] = x;
    cursor->size++;
    cursor->ptr[i + 1] = child;
  }
  
  else{
    Node* newInternal = new Node;
    int fix = 1;
    string virtualKey[FANOUT_VALUE + 1 + fix];
    Node* virtualPtr[FANOUT_VALUE + 2];
    
    for(int i = 0; i < FANOUT_VALUE; i++){
      virtualKey[i] = cursor->key[i];
    }
    
    for(int i = 0; i < FANOUT_VALUE + 1; i++){
      virtualPtr[i] = cursor->ptr[i];
    }

    int i = 0, j;

    while (x > virtualKey[i]&& i < FANOUT_VALUE){
      i++;
    }

    for(int j = FANOUT_VALUE + 1;j > i; j--){
      virtualKey[j]= virtualKey[j - 1];
    }

    virtualKey[i] = x;

    for(int j = FANOUT_VALUE + 2;j > i + 1; j--){
      virtualPtr[j]= virtualPtr[j - 1];
    }
    
    virtualPtr[i + 1] = child;
    newInternal->IS_LEAF = false;
    
    cursor->size= (FANOUT_VALUE + 1) / 2;
    newInternal->size= FANOUT_VALUE - (FANOUT_VALUE + 1) / 2;

    for(i = 0, j = cursor->size + 1;i < newInternal->size;i++, j++){
      newInternal->key[i]= virtualKey[j];
    }
    
    for(i = 0, j = cursor->size + 1;i < newInternal->size + 1;i++, j++){
      newInternal->ptr[i]= virtualPtr[j];
    }
    
    if(cursor == root){
      Node* newRoot = new Node;
      newRoot->key[0]= cursor->key[cursor->size];
      newRoot->ptr[0] = cursor;
      newRoot->ptr[1] = newInternal;
      newRoot->IS_LEAF = false;
      newRoot->size = 1;
      root = newRoot;
    }
    
    else{
      updateInternalNode(cursor->key[cursor->size],findParent(root,cursor),newInternal);
    }
  }
}

Node* BPTree::findParent(Node* cursor,Node* child){
  Node* parent;
  if(cursor->IS_LEAF|| (cursor->ptr[0])->IS_LEAF){
    return NULL;
  }

  for(int i = 0;i < cursor->size + 1; i++){
    if(cursor->ptr[i] == child){
      parent = cursor;
      return parent;
    }

    else{
      parent = findParent(cursor->ptr[i],child);
      
      if(parent != NULL)
	return parent;
    }
  }

  return parent;
}

Node* BPTree::getRoot(){
  return root;
}

int main(){
  BPTree node;
  
  int i=0;
  string english,bangla,searchEnglish;
  ifstream ifile;
  ifile.open("dictionary.txt");
  if(!ifile) return 0;
  while(ifile>>english){
    getline(ifile,bangla);
    node.insert(english, bangla);
  }

  int* index = new int;
  Node* leaf = node.search("abroad", index);
  if(leaf!=NULL) cout<<leaf->key[*index]<<": "<<leaf->data[*index]<<std::endl;
  leaf = node.search("abrogate", index);
  if(leaf!=NULL) cout<<leaf->key[*index]<<": "<<leaf->data[*index]<<std::endl;

  return 0;
}
