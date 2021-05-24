struct Node{
    int value;
    Node* prev;
    Node* next;
};

class DLL{
public:
    DLL();
    ~DLL();
    bool search(int);
    void insert(Node*, int);
    void erase(Node*);  /*後に、返り値を出すように変更？*/
    int* pminimum;
    int* pmaximum;

    //for debug
    void showlist();

private:
    void update(int);
    Node* head;
};