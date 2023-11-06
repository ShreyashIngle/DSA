int main()
{

    Node *root = NULL;
    root = InsertNonRecur(root, 50);
    root = InsertNonRecur(root, 20);
    root = InsertNonRecur(root, 70);
    root = InsertNonRecur(root, 10);
    root = InsertNonRecur(root, 30);
    root = InsertNonRecur(root, 90);
    root = InsertNonRecur(root, 110);

    LevelOrderTraversal(root);

    cout << "Inorder:";
    Inorder(root);
    cout << endl;

    root = Delete(root, 10);
    LevelOrderTraversal(root);

    // root = Delete(root, 20);
    // cout << "Inorder:";
    // Inorder(root);
    // cout << endl;

    // cout << maxDepth(root);
    /*cout<<endl;
    cout<<"Preorder:";
    Preorder(root);
    cout<<endl;

    cout<<"Postorder:";
    Postorder(root);
    cout<<endl;*/

    int key = 50;

    if (SearchNonRecur(root, key) == NULL)
    {
        cout << key << " Not found";
    }
    else
    {
        cout << key << " is found" << endl;
    }

    int k = 13;

    if (Search(root, k) == NULL)
    {
        cout << k << " Not found";
    }
    else
    {
        cout << k << " is found" << endl;
    }

    cout << endl
         << minVal(root)->data;

    mirrorBST(root);
    LevelOrderTraversal(root);