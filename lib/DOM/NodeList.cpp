#include "NodeList.h"

void
Node::List::insert (Node* node)
{
    _nodes.push_back(node);
}

void
Node::List::insert (Node* node, unsigned long index)
{
    _nodes.insert(_nodes.begin+index, node);
}

Node*
Node::List::remove (unsigned long index)
{
    Node* node = _nodes.at(index);
    _erase(_nodes.begin()+index);
    
    return node;
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

bool
Node::List::empty (void)
{
    return _nodes.empty();
}
