// { Driver Code Starts
// A recursive program to add two linked lists 

#include <iostream> 
using namespace std;

struct Node 
{ 
	int data; 
	struct Node* next; 
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
}; 

void append(Node** head_ref, Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void push(Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node(new_data); 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 

/* A utility function to print linked list */
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout<<node->data<<" ";
		node = node->next; 
	} 
	cout<<endl;
} 

// A utility function to swap two pointers 
void swapPointer( Node** a, Node** b ) 
{ 
	Node* t = *a; 
	*a = *b; 
	*b = t; 
} 

Node* addSameSize(Node* head1, Node* head2, int* carry) ;

void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) ;


// The main function that adds two linked lists represented by head1 and head2. 
// The sum of two lists is stored in a list referred by result 
void addList(Node* head1, Node* head2, int size1, int size2, Node** result) 
{ 
	Node *cur; 
    if (head1 == NULL) { 
		*result = head2; 
		return; 
	}

	if (head2 == NULL) 
	{ 
		*result = head1; 
		return; 
	}
	
	int carry = 0; 

	if (size1 == size2) 
		*result = addSameSize(head1, head2, &carry); 
    else
	{ 
		int diff = abs(size1 - size2); 

		if (size1 < size2) 
			swapPointer(&head1, &head2); 

		for (cur = head1; diff--; cur = cur->next);
		
        *result = addSameSize(cur, head2, &carry); 
        
		addCarryToRemaining(head1, cur, &carry, result); 
	} 

	if (carry) 
		push(result, carry); 
} 

// Driver program to test above functions 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    Node *head1 = NULL, *tail1 = NULL;
	    Node *head2 = NULL, *tail2 = NULL;
	    Node *result = NULL; 
        int size1, size2;
        cin>>size1>>size2;
        
        int temp;
        for(int i = 1; i<=size1; i++){
            cin>>temp;
            append(&head1, &tail1, temp);
        }
        for(int i = 1; i<=size2; i++){
            cin>>temp;
            append(&head2, &tail2, temp);
        }
        
        addList(head1, head2, size1, size2, &result); 
        printList(result); 
	}
    return 0; 
} 
// } Driver Code Ends


//User function Template for C++

int c1(Node* head1,Node* head2)
{
    Node* p1=head1;
    Node* p2=head2;
    
    if(p1->next==NULL)
    {
        int j = (p1->data+p2->data)/10;
        p1->data = (p1->data+p2->data)%10;
        
        return j;
    }
    
    int c2 = c1(p1->next,p2->next);
    int c = (c2+p1->data+p2->data)/10;
    p1->data = (p1->data+p2->data+c2)%10;
    
    return c;
}

Node* addSameSize(Node* head1, Node* head2, int* carry) 
{ 
	int j = c1(head1,head2);
	*carry = j;
	return head1;
} 

int cc(Node* head1,Node* curr,int* carry)
{
    Node* p = head1;
    
    if(p == curr)
    {
        return *carry;
    }
    
    int j = cc(p->next,curr,carry);
    int c = (p->data+j)/10;
    p->data = (head1->data+j)%10;
    
    return c;
}
void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) 
{ 
    *result = head1;
	int j = cc(head1,curr,carry);
	*carry = NULL;
}
