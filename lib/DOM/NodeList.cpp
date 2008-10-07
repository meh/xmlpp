#include "NodeNodeList.h"

void
Node::NodeList::insert (Node* node)
{
    _nodes.push_back(node);
}

void
Node::NodeList::insert (Node* node, unsigned long index)
{
    _nodes.insert(_nodes.begin+index, node);
}

Node*
Node::NodeList::replace (Node* node, unsigned long index)
{
    Node* replaced = _nodes.at(index);
    _nodes[index]  = node;

    return replaced;
}

Node*
Node::NodeList::remove (unsigned long index)
{
    Node* node = _nodes.at(index);
    _erase(_nodes.begin()+index);
    
    return node;
}

Node*
Node::NodeList::item (unsigned long index)
{
    if (index >= this->length()) {
        return NULL;
    }
    
    return _nodes[index];
}

unsigned long
Node::NodeList::length (void)
{
    return _nodes.size();
}

bool
Node::NodeList::empty (void)
{
    return _nodes.empty();
}
