#include "Graph.hpp"

// add vertices to our adjacency matrix
void Graph::addVertex(std::string label){
    adj[label];
};

// remove vertices from our adjacency matrix
void Graph::removeVertex(std::string label){
    adj.erase(label);
    for(auto i : adj){
        i.second.erase(label);
    }
}

// add edges to our adjacency matrix
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight){
    // we do both possibilities because this is bidirectional
    adj[label1][label2] = weight;
    adj[label2][label1] = weight;
  
};

// remove edges from our adjacency matrix
void Graph::removeEdge(std::string label1, std::string label2){
    // again, we do this for both because this is bidirectional
    adj[label1].erase(label2);
    adj[label2].erase(label1);
};

// finds shortest path, and also keeps track of the path we took to get there, along with that distance
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path){
  
    //map for vertices we already visited and queue for BFS
    std::map<std::string, int> visited;
    std::queue<std::string> unvisited;
  
    // initiate all distances to infinity at the beginning, except the startLable as that is zero
    for(auto i : adj){
        if(i.first ==  startLabel){
            shortest_path[i.first] = 0;
            prev_path[i.first] = startLabel;
        }
        else{
            shortest_path[i.first] = std::numeric_limits<unsigned long>::max();
            prev_path[i.first] = "\0";
        }
    }

    // adding our starting node to our unvisited queue
    unvisited.push(startLabel);
  
    while(!unvisited.empty()){

        // get first element of the queue
        std::string current = unvisited.front();
    
        // getting the distance of the node
        unsigned long shortest_dist = shortest_path[current];
        for(auto edge : adj[current]){
            std::string neighbor = edge.first;
            // if the neighbor isn't visited then add them to the unvisited queue
            if(!visited[neighbor]) {
                unvisited.push(neighbor);
            }

            // distance between our start node and the neighbor
            unsigned long dist = edge.second;

            /* if the shortest distance from node to neighbor is less than what is currently there 
            then we update the distance to our nodes shortest distance + distance between two nodes */
            if(shortest_dist + dist < shortest_path[neighbor]){
                prev_path[neighbor] = current;
                shortest_path[neighbor] = shortest_dist + dist;
            }
        }
        // move node out of the unvisited queue and mark it as visited
        unvisited.pop();
        visited[current] = 1;
  }
  
    // starting from our end-point, we work our way backwards all the way to start node, where we update the path
    std::string cur = endLabel;
    while(cur != startLabel){
        path.insert(path.begin(), cur);
        cur = prev_path[cur];
    }
    path.insert(path.begin(), startLabel);
  
    // return the path distance (shortest)
    return shortest_path[endLabel];
}