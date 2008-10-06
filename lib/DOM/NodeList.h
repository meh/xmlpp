#if defined(XMLPP_NODE_H)

class List
{
  public:
    List (void) {};

    void insert (Node* node)

    Node* item (unsigned long index);
    unsigned long length (void);

  private:
    std::vector<Node*> _nodes;
};

#endif

