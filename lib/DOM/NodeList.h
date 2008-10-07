#if defined(XMLPP_NODE_H)

class List
{
  public:
    List (void) {};

    void insert (Node* node)
    void insert (Node* node, unsigned long index);

    Node* replace (Node* node, unsigned long index);

    Node* remove (unsigned long index);

    Node* item (unsigned long index);

    unsigned long length (void);

    bool empty (void);

  private:
    std::vector<Node*> _nodes;
};

#endif

