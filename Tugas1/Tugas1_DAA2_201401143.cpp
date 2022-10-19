#include <iostream>
using namespace std;

struct BST{
	int data;
	BST* kiri;
	BST* kanan;
};

BST* InsertNode(int data, BST* tree){
	if(tree==NULL){
		BST* NewNode = new BST;
		NewNode->data = data;
		NewNode->kiri = NULL;
		NewNode->kanan = NULL;
		tree = NewNode;
	}else if(tree->data > data){
		tree->kiri = InsertNode(data, tree->kiri);
	}else{
		tree->kanan = InsertNode(data, tree->kanan);
	}
	return tree;
}

bool SearchNode(int data, BST* tree){
	if(tree==NULL) return false;
	else if(tree->data == data) return true;
	else if(tree->data < data) return SearchNode(data, tree->kanan);
	else return SearchNode(data, tree->kiri);
}

void PrintNodes(BST** tree){
	if((*tree)!=NULL){
		cout<<(*tree)->data<<",";
		PrintNodes(&(*tree)->kiri);
		PrintNodes(&(*tree)->kanan);
		cout<<endl;
	}
}

int main(){
	int a[10] = {4,1,9,6,2,5,3,8,7,0};
	
	BST* Pohon = NULL;
	
	for(int i=0;i<10;i++){
		Pohon = InsertNode(a[i], Pohon);
	}
	if(!SearchNode(7, Pohon)) cout<<"Tidak ";
	cout<<"Ada 7"<<endl;
	if(!SearchNode(11, Pohon)) cout<<"Tidak ";
	cout<<"Ada 11"<<endl;
	
    cout << endl;
    PrintNodes(&Pohon);
	
	
	
}
