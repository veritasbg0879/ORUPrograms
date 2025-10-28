/* Bella Goodman, Kandice Coop
Team 4
Dr. Wheat
CSC 255 Data Structures
Program 10 - Graphs (Dijkstra)
This is the .cpp file for the Graphs program. Graphs consist of vertices and
edges, and the edges can have weight attributes that we can organize according
to priority. Directed graphs are a whole other beast that we'll get to later.
*/

#include <iostream>

#include "p10.h"


using namespace std;

//make two non-member functions min and max to compare values and pick the
//lowest and highes

int min(int x, int y) {
    int min = x;
    
    if (x > y) {
        min = y;
    }
    return min;
}

int max(int x, int y) {
    int max = x;
    
    if (y > x) {
        max = y;
    }
    return max;
}


//******************************************************************************

/*Bella
set up the constructor for your graph so it gets created correctly. set the 
attributes of the graph to match what was passed in and then create a new array
with n^2 elements to hold the matrix and then set up another array of pointers
to point to each section of the matrix. then, fill each spot with 0s. initialize
intList labels to hold the labels for each vertex and set vCount and eCount to 
0. also work out all the new arrays and the const values
*/

Graph::Graph(int n, bool directed)
    : INFINITE(1000000),
      X(0),
      Y(1)
{
    this->n = n;
    this->directed = directed;
    
    int *b = new int[n * n];
    a = new int*[n];
    
    for (int i = 0; i < n; i++) {
        a[i] = &b[i * n];
        
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    
    labels = new intList(n);
    q = new iQ(n);
    vCount = 0;
    eCount = 0;
    lambda = new int[n];
    set = new int[n];
    visited = new bool[n];
    predecessor = new int[n];
}

//******************************************************************************

/*Bella
clear out all the arrays by setting the whole thing to 0 and then deleting the
pointer array. also delete the labels intlist
*/

Graph::~Graph() {
    delete [] a[0];
    delete [] a;
    delete labels;
    delete q;
    delete[] lambda;
    delete[] set;
    delete[] visited;
    delete[] predecessor;
}

//******************************************************************************

/*Kandice
set up the private dijkstra that recieves an int input
*/

void Graph::dijkstra (int s) {
    int minV;
    int i;
    
    for (i = 0; i < vCount; ++i) {
        lambda[i] = INFINITE;
        set[i] = Y;
    }
    
    set[s] = X;
    lambda[s] = 0;
    
    for (int v = 0; v < vCount; v++) {
    if (v != s) {
        if (a[s][v]) {
        lambda[v] = a[s][v];
        }
    }
    }
    
    // Dijkstra's algorithm
    while (minLambdaY(minV)) {
        set[minV] = X;
            
        for (int v = 0; v < vCount; ++v) {
            if (a[minV][v] > 0 && set[v] == Y) {
                lambda[v] = min(lambda[v], lambda[minV] + a[minV][v]);
            }
        }
    }
}
    
//******************************************************************************

/*Bella
set up the cute little array with all our distance values and do all the
calculations
*/

bool Graph::minLambdaY(int &minV) {
    bool rc = false;
    int minVal = INFINITE;
    minV = -1;
    
    for (int i = 0; i < vCount; i++) {
        if (set[i] == Y) {
            if (lambda[i] <= minVal) {
                minVal = lambda[i];
                minV = i;
            }
            rc = true;
        }
    }
    return rc;
}
    
//******************************************************************************

/*Bella
getIndex of the labels and return that to get the index. pretty nifty trick
*/

int Graph::labelToVid(int label) const {
    return labels->getIndex(label);
}

//******************************************************************************

/*Bella
return -1 if it doesnt exist and if it does awesome return the label
*/

int Graph::vidToLabel(int vid) const {
    int rc;
    labels->readAt(vid, rc);
    
    if(rc < 0) {
        rc = -1;
    }
    return rc;
    
}

//******************************************************************************

/*Bella
create a vertex! It would be a little pointless to have a real graph where we 
can't draw anything, so why would we do that for a data structure of a graph?
see if there's room in the list and then add a vertex to the labels list and
increase vCount.
*/

bool Graph::createV(int label) {
    bool rc = !isV(label);
    
    if (rc) {
        if (vCount < n) {
            labels->add(label);
            vCount++;
        } else {
            rc = false;
        }
    }
    return rc;
}

//******************************************************************************

/*Bella
add edges! They're the lines between the vertices and they have attributes named
weights, which can help us organize or prioritize them. see if the proper 
vertices exist and create them if they don't. if they do, awesome! add the edge
and add the weight to the matrix so we can tell there's an edge there.
*/

bool Graph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;
    int vVid;
    int uVid;
    int newCount = 0;
    
    if ((weight > 0) && (!isEdge(uLabel, vLabel))){    
        bool V = isV(vLabel);
        bool U = isV(uLabel);
        int cCount = 0;
    
        if (!V) {
            cCount++;
        }

        if (!U) {
            cCount++;
        }

        if (cCount <= (n - vCount)) {
            createV(uLabel);
            createV(vLabel);
            uVid = labelToVid(uLabel);
            vVid = labelToVid(vLabel);
            a[uVid][vVid] = weight;
            eCount++;
            rc = true;
        
        }
    }
    return rc;
}

//******************************************************************************

/*Bella
delete that sucker and set the weight to 0 so we know there's nothing there 
anymore.
*/

bool Graph::deleteEdge(int uLabel, int vLabel) {
    bool rc = isEdge(uLabel, vLabel);
    
    if (rc) {
        int uVid = labelToVid(uLabel);
        int vVid = labelToVid(vLabel);
    
        a[uVid][vVid] = 0;
        eCount--;
        rc = true;
    }
    
    return rc;
}

//******************************************************************************

/*Bella
clear the graph. set everything to 0 again and clear out the labels list. set 
vCount and eCount to 0 since there are no longer any vertices or edges.
*/

void Graph::clear() {
    for (int i = 0; i < vCount; i++) {
        for (int j = 0; j < vCount; j++) {
            a[i][j] = 0;
        }
    }

    labels->clear();
    vCount = 0;
    eCount = 0;
}

//******************************************************************************

/*Bella
does the edge exist? if it does, awesome. tell the user that via a bool value.
if not, let them know that via the same boolean value.
*/

bool Graph::isEdge(int uLabel, int vLabel) const {
    bool rc = false;
    
    if ((isV(uLabel)) && (isV(vLabel))) {
        int vVid = labelToVid(vLabel);
        int uVid = labelToVid(uLabel);
        
        if (a[uVid][vVid] > 0) {
            rc = true;
        }
    }
    return rc;
}

//******************************************************************************

/*Bella
is the label we get associated with a vertex? whatever happens we get a number
so we have to double check that the number isn't -1 and then we can tell them
whether or not the vertex is for real.
*/

bool Graph::isV(int label) const {
    return (labels->getIndex(label) >= 0);
}

//******************************************************************************

/*Bella
usually inDegrees and outDegrees only apply to directed graphs. this graph isn't
directed, but it still has these functions. how many edges end at this vertex? 
count them all and then add them together to get the inDegree of the spot.
*/

int Graph::inDegree(int label) const {
    int rc = -1;
    int Vid = labelToVid(label);
    
    if (Vid >= 0) {
        rc = 0;
        
        for (int i = 0; i < vCount; i++) {
            if (a[i][Vid] > 0) {
            rc++;
            }
        }
    }
    return rc;
}

//******************************************************************************

/*Bella
outDegrees are a measure of how many edges begin at this vertex. again, these
are for DIRECTED graphs so we can organize things into what happens first
and so on. 
*/

int Graph::outDegree(int label) const {
    int rc = -1;
    int Vid = labelToVid(label);
    
    if (Vid >= 0) {
        rc = 0;
        
        for (int i = 0; i < vCount; i++) {
            if (a[Vid][i] > 0) {
            rc++;
            }
        }
    }
    return rc;
}

//******************************************************************************

/*Bella
return the overall size of the graph (not necessarily filled spots, merely spots
that exist)
*/

int Graph::sizeV() const {
    return n;
}

//******************************************************************************

/*Bella
return vCount, which is the total number of vertices
*/

int Graph::sizeUsedV() const {
    return vCount;
}

//******************************************************************************

/*Bella
return eCount since its the amount of edges
*/

int Graph::sizeE() const {
    return eCount;
}

//******************************************************************************

/*Bella
print out a very nice list of the nodes and the matrix with the weights in their
correct spots. Also print the count of vertices and edges and all the things
so we can double-check that it actually works.
*/

void Graph::printIt() const {
    cout << "Graph info:\n";
    cout << "  Graph size = " << sizeV() << endl;
    cout << "  vCount = " << sizeUsedV() << endl;
    cout << "  eCount = " << sizeE() << endl;
    cout << "\nGraph contents:\n";
    
    for (int r = 0; r < vCount; r++) {
        int label;
        labels->readAt(r, label);
        cout << "  Node(" << r << "," << label << "):";
        
        for (int c = 0; c < vCount; c++) {
            cout << " " << a[r][c];
        }
    cout << endl;
    }

    cout << "Degree table (in, out)\n";

    for (int r = 0; r < sizeUsedV(); r++) {
        int label;
        labels->readAt(r, label);
        cout << "  Node(" << r << "," << label << "):";
        cout << " " << inDegree(label) << ", " << outDegree(label) << endl;
    }
    
}

//******************************************************************************

/*Bella
search that bread!! just kidding. start with a node and then visit all of it's 
neighbors then visit all the next neighbors throughout the graph.
*/

void Graph::breadthFirstSearch(int u, bool key) const {
    if (u >= 0) {
        int val = 0;
        bool* visited = new bool[vCount];
        
        for (int i = 0; i < vCount; i++) {
            visited[i] = false;
        }

        q->clear();
        visited[u] = true;
        q->enq(u);
        int i = 0;
        
        while (q->count() > 0) {
            q->deq(val);
            
            if (key) {
                int label;
                labels->readAt(val, label);
                cout << "       Item " << i++ << " is (" << val << "," << 
                label << ")" << endl;
            }

            for (int i = 0; i < vCount; i++) {
                if (isEdge(vidToLabel(val), vidToLabel(i))) {
                    if (!visited[i]) {
                        visited[i] = true;
                        q->enq(i);
                    }
                }
            }
        }
    }
}

//******************************************************************************

/*Bella
print up the nodes and make em cute
*/

void Graph::bfPrint(int label) const {
    int v = labelToVid(label);
    
    if (v >= 0) {
        breadthFirstSearch(v, true);
    }
}

//******************************************************************************

/*Bella
are there paths??? ARE THERE??? lmk when i call up this function
*/
bool Graph::isPath(int uLabel, int vLabel) const {
    bool rc = false;
    if (isV(uLabel) && isV(vLabel)) {
        int vID = labelToVid(vLabel);
        int uID = labelToVid(uLabel);
        bool *visited = new bool[vCount];
        
        for (int i = 0; i < vCount; i++) {
            visited[i] = false;
        }
        
        q->clear();

        q->enq(uID);
        int wID;
        
        while(q->deq(wID)) {
            for (int i = 0; i < vCount; i++) {
                if (isEdge(vidToLabel(wID), vidToLabel(i))) {
                    if (!visited[i]) {
                        visited[i] = true;
                        q->enq(i);
                    }
                }
            }
        }
        rc = visited[vID];

        delete [] visited;
    }
    
    return rc;
}

//******************************************************************************

/*Bella
print out a very nice list of the nodes and the matrix with the weights in their
correct spots. Also print the count of vertices and edges and all the things
so we can double-check that it actually works.
*/

void Graph::printPaths() const {
    for (int u = 0; u < vCount; u++) {
        for (int v = 0; v < vCount; v++) {
            if (isPath(vidToLabel(u), vidToLabel(v))) {
                cout << vidToLabel(u) << " does have a path to " << vidToLabel(v)
                << endl;
            } else {
                cout << vidToLabel(u) << " does not have a path to " << 
                vidToLabel(v) << endl;
            }
        }
    }
}

//******************************************************************************

/*Kandice
*/

bool Graph::dijkstra (int sLabel, int dLabel, int &distance) {
    bool rc = false;
    int s = labelToVid(sLabel);
        int d = labelToVid(dLabel);

    distance = -1;
        // Check if the labels correspond to valid vertices
        if ((s >= 0) && (d >= 0)) {
            dijkstra(s);
            // Check if the destination vertex is reachable
            distance = lambda[d];
        rc = true;
        }

    return rc;
}
