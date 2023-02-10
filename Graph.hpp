#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphBase.hpp"
#include <vector>
#include <map>
#include <queue>
#include <limits>

class Graph : public GraphBase {
private:
    std::map<std::string, unsigned long> shortest_path;
    std::map<std::string, std::string> prev_path; 
    std::map<std::string, std::map<std::string, unsigned long>> adj;

public:
    Graph(){};
    ~Graph(){};
    
    virtual void addVertex(std::string label);
    virtual void removeVertex(std::string label);
    virtual void addEdge(std::string label1, std::string label2, unsigned long weight);
    virtual void removeEdge(std::string label1, std::string label2);
    virtual unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
};

#endif