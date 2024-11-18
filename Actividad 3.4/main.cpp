/*
    Act 3.4 - Comprehensive BST activity (competence evidence)
    Created by Ricardo Gaspar Ochoa, Gilberto Malagamba Montejo and Gerardo Fregoso Jimenez on 17/11/24.
    This code Find the five IPs with the most accesses.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Función para validar si una cadena es una IP válida
bool isValidIP(const string &ip) {
    int dots = 0;
    for (char c : ip) {
        if (c == '.') dots++;
        else if (!isdigit(c)) return false;
    }
    return dots == 3;
}

struct TreeNode {
    int accessCount;
    string ipAddress;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int count, string ip) : accessCount(count), ipAddress(ip), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode *root;

    void insert(TreeNode *&node, int count, const string &ip) {
        if (!node) {
            node = new TreeNode(count, ip);
        } else if (count < node->accessCount) {
            insert(node->left, count, ip);
        } else {
            insert(node->right, count, ip);
        }
    }

    void inorder(TreeNode *node, vector<pair<int, string>> &result) {
        if (node) {
            inorder(node->left, result);
            result.emplace_back(node->accessCount, node->ipAddress);
            inorder(node->right, result);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int count, const string &ip) {
        insert(root, count, ip);
    }

    vector<pair<int, string>> getSortedData() {
        vector<pair<int, string>> result;
        inorder(root, result);
        return result;
    }
};

int main() {
    ifstream file("./bitacora.txt");
    if (!file) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    map<string, int> ipAccessCount;
    string line;

    while (getline(file, line)) {
        size_t ipStart = line.find(' ', line.find(' ', line.find(' ') + 1) + 1);
        size_t ipEnd = line.find(':', ipStart);
        if (ipStart != string::npos && ipEnd != string::npos) {
            string ip = line.substr(ipStart + 1, ipEnd - ipStart - 1);
            if (isValidIP(ip)) {
                ipAccessCount[ip]++;
            }
        }
    }

    file.close();

    BST bst;
    for (const auto &entry : ipAccessCount) {
        bst.insert(entry.second, entry.first);
    }

    vector<pair<int, string>> sortedData = bst.getSortedData();
    cout << "Cantidad de IPs unicas: " << sortedData.size() << endl;

    cout << "Top 5 IPs con mas accesos:" << endl;
    for (int i = sortedData.size() - 1, count = 0; i >= 0 && count < 5; --i, ++count) {
        cout << "IP: " << sortedData[i].second << " - Accesos: " << sortedData[i].first << endl;
    }

    return 0;
}
