//#include "BinaryTreeBuilder.h"
//#include "SimpleCondition.h"
//#include "AndCondition.h"
//#include "OrCondition.h"
//#include "ConditionsManager.h"
//#include <stdexcept>
//#include <stack>
//#include <fstream>
//
//BinaryTreeBuilder::Node::Node(ConditionBase* cond) : condition(cond), left(nullptr), right(nullptr) {}
//
//BinaryTreeBuilder::BinaryTreeBuilder() : root(nullptr) {}
//
//BinaryTreeBuilder::~BinaryTreeBuilder() {
//    deleteTree(root);
//}
//
//void BinaryTreeBuilder::deleteTree(Node* node) {
//    if (node) {
//        deleteTree(node->left);
//        deleteTree(node->right);
//        delete node->condition;
//        delete node;
//    }
//}
//
//ConditionBase* BinaryTreeBuilder::buildTree(const std::vector<SimpleCondition*>& conditions, const std::vector<std::string>& operators) {
//    if (conditions.empty()) {
//        return nullptr;
//    }
//    if (conditions.size() != operators.size() + 1) {
//        throw std::runtime_error("Number of conditions and operators don't match");
//    }
//
//    root = new Node(conditions[0]);
//    Node* current = root;
//
//    for (size_t i = 0; i < operators.size(); ++i) {
//        current = buildNode(current, conditions[i + 1], operators[i]);
//        current = current->left; 
//    }
//
//    return root->condition;
//}
//
//BinaryTreeBuilder::Node* BinaryTreeBuilder::buildNode(Node* currentRoot, SimpleCondition* newCondition, const std::string& op) {
//    ConditionBase* combinedCondition = nullptr;
//    if (op == "&&") {
//        combinedCondition = new AndCondition(currentRoot->condition, newCondition);
//    }
//    else if (op == "||") {
//        combinedCondition = new OrCondition(currentRoot->condition, newCondition);
//    }
//    else {
//        throw std::runtime_error("Unknown operator: " + op);
//    }
//
//    Node* newNode = new Node(combinedCondition);
//    currentRoot->left = newNode; 
//    return newNode;
//}
//
//void BinaryTreeBuilder::exportToJson(const std::string& filename) {
//    if (root) {
//        exportBinaryTreeToJson(root, filename);
//    }
//}
//
//void BinaryTreeBuilder::exportBinaryTreeToJson(Node* root, const std::string& filename) {
//    std::ofstream file(filename);
//    if (!file.is_open()) {
//        throw std::runtime_error("Cannot open file: " + filename);
//    }
//
//    nlohmann::json j;
//    std::stack<std::pair<Node*, nlohmann::json*>> stack;
//    Node* current = root;
//    nlohmann::json* current_json = &j;
//
//    while (current || !stack.empty()) {
//        while (current) {
//            nlohmann::json node_json;
//            node_json["condition"] = current->condition->toJson();
//            node_json["left"] = nlohmann::json::object();
//            node_json["right"] = nlohmann::json::object();
//
//            (*current_json)["node"] = node_json;
//            stack.push({ current, current_json });
//
//            current_json = &((*current_json)["node"]["left"]);
//            current = current->left;
//        }
//        if (!stack.empty()) {
//            auto [node, json_ref] = stack.top();
//            stack.pop();
//            current_json = &((*json_ref)["node"]["right"]);
//            current = node->right;
//        }
//    }
//
//    file << j.dump(4); 
//    file.close();
//}
