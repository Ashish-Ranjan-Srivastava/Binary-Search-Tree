#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
int l=0;
void insert(node* &root,int key)
{
	node *n1=new node;
	n1->data=key;
	n1->left=NULL;
	n1->right=NULL;
	//l++;
	//cout<<l<<"\n";
	if(root==NULL)
	{
		root=n1;
	}
	else
	{
		if(key>root->data )
			insert(root->right,key);
		else if(key<root->data)
			insert(root->left,key);
	}
}
void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout<<p->data<<endl;
        inorder(p->right);
    }
}

node* min(node* root)
{
	node* rec=root;
	while (rec->left != NULL) 
        rec = rec->left; 
    return rec; 
	
}
void del(node * root,int val)
{
	
	if(val<root->data)
		del(root->left,val);
	else if(val>root->data)
		del(root->right,val);
	else
	{
		node* temp=root;
		if(temp->left==NULL && temp->right!=NULL)
		{
			temp->data=temp->right->data;
			temp=temp->right;
			delete temp;
			
		}
		else if(temp->left!=NULL && temp->right==NULL)
		{
			temp->data=temp->left->data;
			temp=temp->left;
			delete temp;
		}
		else if(temp->left==NULL && temp->right==NULL)
			delete temp;
		else
		{
		//	cout<<"Sfvsvdf";
			node* mc=min(temp->right);
		//	cout<<mc->data;
		//	cout<<temp->data;
			temp->data=mc->data;
			delete mc;
			
		}
	}
}
void printSpiral(node *root)
{
	if(root==NULL)
	{
		cout<<"not element"<<endl;
	}
	else
	{
		stack<node*> s1;
		stack<node*> s2;
		s1.push(root);
		while(!s1.empty() || !s2.empty() )
		{
			while(!s1.empty())
			{
				node *temp=s1.top();
				cout<<temp->data<<" ";
				s1.pop();
				 if (temp->right) 
                	s2.push(temp->right); 
            	if (temp->left) 
               		 s2.push(temp->left); 
			}
			while(!s2.empty())
			{
				node *temp=s2.top();
				cout<<temp->data<<" ";
				s2.pop();
				if (temp->left) 
					s1.push(temp->left);
					
				if (temp->right) 
					s1.push(temp->right);
			}
		}
	}
}



void printSpiral2(node *root)
{
	if(root==NULL)
	{
		cout<<"not element"<<endl;
	}
	else
	{
		stack<node*> s1;
		stack<node*> s2;
		s1.push(root);
		while(!s1.empty() || !s2.empty() )
		{
			while(!s1.empty())
			{
				node *temp=s1.top();
				cout<<temp->data<<" ";
				s1.pop();
				 
            	if (temp->left) 
               		 s2.push(temp->left); 
               		 
               		 if (temp->right) 
                	s2.push(temp->right); 
			}
			while(!s2.empty())
			{
				node *temp=s2.top();
				cout<<temp->data<<" ";
				s2.pop();
				
				if (temp->right) 
					s1.push(temp->right);
					
					if (temp->left) 
					s1.push(temp->left);
			}
		}
	}
}
void lb(node* root)//left side wala
{
	if(root==NULL)
		return ;
	else
	{
		if(root->left !=NULL)
			{
				cout<<root->data<<" ";
				lb(root->left);
			}
			else if(root->right!=NULL)
			{
				cout<<root->data<<" ";
				lb(root->right);
			}
	}
		
}

void rb(node* root)//right side wala
{
	if(root==NULL)
		return ;
	else
	{
		if(root->right !=NULL)
			{
				rb(root->right);
				cout<<root->data<<" ";
				
			}
			else if(root->left!=NULL)
			{
				lb(root->left);
				cout<<root->data<<" ";
				
			}
	}
		
}
void ln(node *root)
{
	if(root==NULL)
		return ;
	else
	{
		ln(root->left);
		if(root->left==NULL && root->right==NULL)
			cout<<root->data<<" ";
		ln(root->right);
	}
	
}
void displayBoundary(node *root)
{
	cout<<root->data<<" ";
	lb(root->left);
	ln(root->left);
	ln(root->right);
	rb(root->right);
}
int main()
{
	node *root=NULL;
	int arr[]={14,12,20,10,13,15,30,25,35};
	for(int i=0;i<9;i++)
	{
		insert(root,arr[i]);
	}	
	
	inorder(root);
	cout<<"insertion"<<endl;
	insert(root,120);
	inorder(root);
	node *c=min(root);
	cout<<c->data;
	cout<<"-----------------------------------------------------------"<<endl;
	printSpiral(root);
	cout<<"--------------------------------------------"<<endl;
	printSpiral2(root);
	cout<<endl<<"boundaryTraversal--------------------------------------------"<<endl;
	displayBoundary(root);
}
