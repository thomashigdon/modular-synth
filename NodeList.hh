#ifndef NodeList_hh
#define NodeList_hh
#include <vector>

class Node;

class NodeList
{
public: 
  NodeList();
  NodeList(Node *node);
  NodeList(Node *node1, Node *node2);

  Node* operator[](int index)
  {
    return mNodes[index];
  }

  unsigned int size();

  std::vector<Node *> mNodes;
};
#endif
