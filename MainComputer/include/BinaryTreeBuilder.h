#ifndef BINARY_TREE_BUILDER_H
#define BINARY_TREE_BUILDER_H

#include <vector>
#include <string>
#include "ConditionBase.h"

class SimpleCondition;

class BinaryTreeBuilder {
private:
    struct Node {
        ConditionBase* condition;
        Node* left;
        Node* right;
        Node(ConditionBase* cond);
    };
    Node* root;
    void deleteTree(Node* node);
    Node* buildNode(Node* currentRoot, SimpleCondition* newCondition, const std::string& op);
    void exportBinaryTreeToJson(Node* root, const std::string& filename);
public:
    BinaryTreeBuilder();
    ~BinaryTreeBuilder();
    ConditionBase* buildTree(const std::vector<SimpleCondition*>& conditions, const std::vector<std::string>& operators);
    void exportToJson(const std::string& filename);
};

#endif 
