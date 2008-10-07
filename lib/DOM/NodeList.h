#if defined(XMLPP_DOM_NODE_H)
#if !defined(XMLPP_DOM_NODELIST_H)
#define XMLPP_DOM_NODELIST_H

class NodeList
{
  public:
    void insert (Node* node);
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
#endif

