#include "NodeList.hh"
#include "Node.hh"

NodeList::NodeList()
{
}

NodeList::NodeList(Node* node)
{
  mNodes.push_back(node);
}

NodeList::NodeList(Node* node1, Node* node2)
{
  mNodes.push_back(node1);
  mNodes.push_back(node2);
}

unsigned int NodeList::size()
{
  return mNodes.size();
}
