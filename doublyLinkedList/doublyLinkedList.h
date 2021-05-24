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
    void erase();  /*後に、返り値を出すように変更？*/
    int* pminimum;
    int* pmaximum;

private:
    void updatemax(int);
    void updatemin(int);
    Node node;
    Node* head;
};