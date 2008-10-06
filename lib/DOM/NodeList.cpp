#include "NodeList.h"

void
Node::List::insert (Node* node)
{
    _nodes.push_back(node);
}

Node*
Node::List::item (unsigned long index)
{
    if (index >= this->length()) {
        return NULL;
    }
    
    return _nodes[index];
}

unsigned long
Node::List::length (void)
{
    return _nodes.size();
}

