# Dijkstra Shortest path algorithm

Dijkstra's shortest path algorithm is a graph traversal algorithm that efficiently finds the shortest path between a starting vertex and all other vertices in a weighted graph. This project was made to illustrate how Dijsktra's Shortest Path algorithm can be implemented using an adjacency matrix in C++

## Usage

To use the code provided in this project simply clone the code from this github on your local machine. Make sure that you have C++ installed. 
> You can verify whether you have C++ installed by running the followig command in your terminal. 
```bash
g++ --version
```

### Compilation

```bash
g++ -std=c++17 -Wall *.cpp
```

This will generate an `a.out` executable (or a.exe if on windows). From there you can run the following command to run the test

## Testing

To be able to test the code in case you may want to make changes or imporvements to the algorithm, there are test located in `PP4Test.cpp` file. Afer you compile your code run the following command to run the test

```bash
./a.out -s
```

After you run that. you will see something similar to this in
your terminal

<img width="445" alt="dijkstra-output" src="https://github.com/Aslanbayli/dijkstra-algorithm/assets/48028559/e67fbce6-9d08-45db-ac57-3b2db1621831">
