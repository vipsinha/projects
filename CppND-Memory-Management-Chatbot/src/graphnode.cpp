#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    
    // VISI: chatbot delete happens in ChatLogic::~ChatLogic() after 
    // before the node deletion
    // TASK 0
    // delete _chatBot;

 
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}
// VISI: executed one time, when load answer graph is executed
void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// TASK 4: _childeNode is owned by Graph node
// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    //_childEdges.push_back(edge);
    // TASK 4: 
    /* `push_back()` creates a copy of the element you are adding to it, 
    and hence you get the error that you are trying to use copy assignment 
    on a `unique_ptr`, which is not allowed. Hence, you need to transfer 
    ownership from the pointer passed into the function to the `unique_ptr` 
    in the `vector` container.*/
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
// VISI: move the node into it
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // TASK 4: Found this error when bot is ran for more queries
    // TASK 5: Also its part
    _chatBot = std::move(chatbot);
    // _chatBot->SetCurrentNode(this);
    _chatBot.SetCurrentNode(this);
}

// VISI: move the node away
void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // VISI: calls the above function
    // TASK 4: Found this error when bot is ran for more queries
    // TASK 5: Also its part
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // TASK 4: Send the raw pointer 
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}