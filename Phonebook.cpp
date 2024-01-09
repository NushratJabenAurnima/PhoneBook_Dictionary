<!DOCTYPE html>
<html>
<body>
<h2>Project Done by &copy; Nushrat Jaben Aurnima. All Rights Reserved .</h2>
</body>
</html>
#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;

void insert_contact();

struct Node
{
    string name, phone;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *create_bst(string name, string phone)
{
    struct Node *newNode = new struct Node;
    newNode->name = name;
    newNode->phone = phone;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key
struct Node *insert_bst(struct Node *&root, string name, string phone)
{
    if (root == NULL)
        return create_bst(name, phone);

    if (name < root->name)
        root->left = insert_bst(root->left, name, phone);
    else if (name > root->name)
        root->right = insert_bst(root->right, name, phone);

    return root;
}

// Function to check if phone number already exists
int read_file(string phone)
{
    string line;
    ifstream myfile("phonebook.txt");

    while (getline(myfile, line))
    {
        size_t pos = line.find("Contact:");
        if (pos != string::npos)
        {
            //checking the number string which is after the "Contact" word
            string ex_phone = line.substr(pos + 9);//"Contact:" has 9 characters
            if (ex_phone == phone)
            {
                myfile.close();
                return 1;
            }
        }
    }

    myfile.close();
    return 0;
}

//function to insert contact
struct Node* insert_contact(struct Node *&root)
{
    string name, phone;
    cout << endl << "Enter Name: ";
    cin >> name;

repeat:
    cout << "Enter Contact: ";
    cin >> phone;

    if (read_file(phone) == 1)
    {
        cout << "Contact already exists. Enter a new contact number for " << name << "." << endl;
        goto repeat;
    }
    else
    {
        // Insert into BST
        root = insert_bst(root, name, phone);
        // Insert into file
        ofstream myfile("phonebook.txt", ios::out | ios::app);
        myfile << "Name: " << name << "\t";
        myfile << "Contact: " << phone << endl;
        myfile.close();
        cout << "Contact has been inserted." << endl;
    }

    return root;
}


// Function to search largest element returns -> the root
struct Node* findMax(struct Node* root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node* delete_contact(Node* root, string contact)
{
    // Deleting from file
    string line;
    ifstream myfile("phonebook.txt");
    ofstream dup("temp.txt");
    int c = 0;

    // Copy to another file except the contact to delete
    while (getline(myfile, line))
    {
        if (line.find(contact) == string::npos)
            dup << line << endl;
        else
            c++;
    }

    myfile.close();
    dup.close();

    if (c == 0)
    {
        cout << "Contact not found in the file." << endl;
    }
    else
    {
        cout << "Contact has been deleted successfully from the file!!" << endl;
        remove("phonebook.txt");
        rename("temp.txt", "phonebook.txt");
    }

     // Remove from BST if it exists
    if (root == NULL)
        return root;

    struct Node* temp = root;
    struct Node* parent = NULL;

    // Search for the node in the BST
    while (temp != NULL && temp->phone != contact)
    {
        parent = temp;
        if (contact < temp->phone)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (temp != NULL)
    {
        // Case 1: No child
        if (temp->left == NULL && temp->right == NULL)
        {
            if (parent == NULL)
                root = NULL;
            else if (parent->left == temp)
                parent->left = NULL;
            else
                parent->right = NULL;

            free(temp);
        }
        // Case 2: One child
        else if (temp->left == NULL)
        {
            if (parent == NULL)
                root = temp->right;
            else if (parent->left == temp)
                parent->left = temp->right;
            else
                parent->right = temp->right;

            free(temp);
        }
        else if (temp->right == NULL)
        {
            if (parent == NULL)
                root = temp->left;
            else if (parent->left == temp)
                parent->left = temp->left;
            else
                parent->right = temp->left;

            free(temp);
        }
        // Case 3: Two children
        else
        {
            struct Node* node = findMax(temp->left);
            temp->phone = node->phone;
            temp->left = delete_contact(temp->left, node->phone);
        }

        cout << "Contact has been deleted successfully from the BST!!" << endl;
    }
    else
    {
        cout << "Contact not found in the BST." << endl;
    }

    return root;
}

// Function to search by contact
void search_contact()
{
    int c=0;
    string contact;
    string line;
    ifstream myfile;
    myfile.open("phonebook.txt");
    cout << "\nEnter the contact you want to search: ";
    cin >> contact;

    while (getline(myfile, line))
    {
        int offset = line.find(contact);

        if (offset != string::npos)
        {
            cout << "\nContact " << contact << " is found." << endl;
            c++;
            myfile.close();
        }
    }

    if(c == 0)
        cout << "\nContact not found\n";
}

// Function to search by name
void search_name()
{
    int c = 0;
    string name;
    string line;
    ifstream myfile;
    myfile.open("phonebook.txt");

    cout << "\nEnter the name you want to find: ";
    cin >> name;

    while (getline(myfile, line))
    {
        int offset = line.find(name);

        if (offset != string::npos)
        {
            cout << endl <<line << endl;
            c++;
        }

    }

    myfile.close();

    if(c == 0)
        cout << "\nName not found\n";
}

// Function to display contacts from file
void display_contact(struct Node *root)
{
    ifstream ex_file("phonebook.txt");

    if (ex_file.is_open())
    {
        string line;
        while (getline(ex_file, line))
        {
            cout << line << endl;
        }
        ex_file.close();
    }
    else
        cout << "Failed to open the file." << endl;

}



int main()
{
    struct Node *root = NULL;
    string contact;
    int choice;
    while(1)
    {
        cout<<endl<<"************** PhoneBook Dictionary *****************\n"<<endl;
        cout<<"1. Add Contact\n";
        cout<<"2. Remove Contact\n";
        cout<<"3. Search by Contact\n";
        cout<<"4. Search by Name\n";
        cout<<"5. Show Contacts\n";
        cout<<"6. Exit\n";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            insert_contact(root);
            break;

        case 2:
            cout<<endl<<"Enter the contact you want to delete: ";
            cin>>contact;
            root = delete_contact(root,contact);
            break;

        case 3:
            search_contact();
            break;

        case 4:
            search_name();
            break;

        case 5:
            cout<<endl;
            display_contact(root);
            break;

        case 6:
            cout<<"The program is ended!!";
            exit(1);
            break;

        default:
            cout<<"Error!! The option is not found!!\n\n";

        }
    }
    return 0;
}
