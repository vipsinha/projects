#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>
#include <memory>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    // TASK 3
    std::vector<std::unique_ptr<GraphNode>> _nodes;
    // VISI: This is going to change in task 4 and moved to graph node
    // TASK 4: It is not used anywhere
    // std::vector<GraphEdge *> _edges;
    // std::vector<std::unique_ptr<GraphEdge>> _edges;

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    // VISI: main function which loads the text and loads into graph function
    void LoadAnswerGraphFromFile(std::string filename);
    // VISI: Sends messages to chatbot object
    void SendMessageToChatbot(std::string message);
    // VISI: Receives messages from the chatbot object
    void SendMessageToUser(std::string message);
    // VISI: Retrieves the image from the chatbot and represent it in GUI
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */