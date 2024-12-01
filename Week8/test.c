#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct contact_t {
      char name[20];
      char tel[11];
      char email[25];
} contact; 
 
struct list_el {
	 contact el;
	 struct list_el *next;
};
typedef struct list_el node;
 
void inDanhSach();
contact readNode();
void removeEnter(char *str);
 
node *root; // trỏ đến nút ở đầu danh sách
node *cur; // trỏ đến nút đang duyêt
node *prev; // trỏ đến nút trước nút đang duyệt, 
// nếu nút đang duyệt là nút đầu tiên trong danh sách thì prev = NULL
 
 
node* makeNewNodeV1() {
	node* new_node = (node*) malloc(sizeof(node));
	strcpy((new_node->el).name, "Tran Van Thanh");
	strcpy((new_node->el).tel, "123456789");
	strcpy((new_node->el).email, "sv2023@hust.edu.vn");
	new_node->next = NULL;
	return new_node;
}
 
void Buoc2() {
	cur = makeNewNodeV1();
	root = cur;
	prev = NULL; 
	inDanhSach();
}
 
void inDanhSach() {
	node *cur = root;
	while(cur != NULL) {
		printf("\n%-25s %-15s %-s", cur->el.name, cur->el.tel, cur->el.email);
		prev = cur;
		cur = cur->next; 
	}
}	
 
node* makeNewNodeV2(contact ct) {
	 node* new_node = (node*)malloc(sizeof(node));
	 new_node->el= ct;
	 new_node->next = NULL;
	 return new_node;
}
 
// Buoc 3
void Buoc3() {
	cur = makeNewNodeV2(readNode());
	root = cur;
	prev = NULL; 
	inDanhSach();
}
 
contact readNode() {
	contact tmp;
	printf("\n Ho ten: ");
	fgets(tmp.name, 20, stdin);
	removeEnter(tmp.name);
	printf("\n So dien thoai: ");
	fgets(tmp.tel, 11, stdin);
	removeEnter(tmp.tel);
	printf("\n Email: ");
	fgets(tmp.email, 25, stdin);
	removeEnter(tmp.email);
	return tmp; 
}
 
void removeEnter(char *str) {
	int i;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == 10 || str[i] == 13)
			str[i] = '\0';
	}
}
 
void displayNode(node* p) {
	if (p == NULL) { 
		printf("NULL Pointer error.\n"); 
		return; 
	}
 
	/* display name, tel, email in columns */
	printf("\n %-25s %-15s %-s \n", p->el.name, p->el.tel, 
		p->el.email);
}
void displayInfo(contact ct) {
	/* display name, tel, email in columns */
	printf("\n %-25s %-15s %-s", ct.name, ct.tel, 
		ct.email);
}
 
void insertAtHead(contact ct) {
	node* new_item = makeNewNodeV2(ct);
	new_item->next = root;
	root = new_item;
	cur = root;
}
 
void Buoc4() {
	contact tmp; int i;	
	root = NULL; 
	cur = NULL; 
	prev = NULL; 
	for(i=0; i<2; i++) {
		tmp = readNode(); 
		insertAtHead(tmp);
		//displayNode(root);
	}
	inDanhSach(); 
}
 
void insertAfterCurrent(contact ct) {
	node* new_node = makeNewNodeV2(ct); // ct is a contact data
	if ( root == NULL ) {/* if there is no element */
		root = new_node;
		cur = root;
	}
	else if (cur == NULL) return;
	else {
   	new_node->next = cur->next;
		cur->next = new_node;
		/* prev=cur; */
		cur = cur->next;
	}
}
 
void Buoc5() {
	contact tmp;
	Buoc4();	
	tmp = readNode(); 
	insertAfterCurrent(tmp);
	printf("\n Sau khi them nut moi vao sau nut hien tai");
	inDanhSach(); 
}
 
void insertBeforeCurrent(contact e) {
	node * new_node = makeNewNodeV2(e);
    if ( root == NULL ) {  /* if there is no element */
		root = new_node; 
		cur = root;
		prev = NULL;
	} else {
   	new_node->next = cur;
		if (cur == root) {/* if cur pointed to first element */
    		root = new_node; /* nut moi them vao tro thanh dau danh sach */
		}
		else prev->next = new_node; // assume prev pointer always point to the previous node
		cur = new_node;
	}
}
 
void updatePrev() {
  	if (root == NULL) { prev = NULL; return; }
	if (root == cur) { prev = NULL; return; }
  	node *tmp = root;
  	while (tmp->next != cur)
		tmp = tmp->next;
	prev = tmp;
}
 
void Buoc6() {
	Buoc4();
	updatePrev();
	printf("\n Con tro cur: %s", cur->el.name);
	if (prev == NULL)
		printf("\n Con tro prev: NULL");
	else 
		printf("\n Con tro prev: %s", prev->el.name);
	/*tmp = readNode(); 
	insertBeforeCurrent(tmp);
	printf("\n Sau khi them nut moi vao sau nut hien tai");
	inDanhSach(); */
}
 
int main() {
	//Buoc6(); 
	//Buoc5(); 
	//Buoc4(); 
	//Buoc2();
	//Buoc3(); 
	//displayNode(root);
	//displayInfo(root->el);
	return 0; 
}