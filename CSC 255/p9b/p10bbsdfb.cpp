/* Bella Goodman, Kandice Coop
Team 4
Dr. Wheat
CSC 255 Data Structures
Program 10 - Dijkstra
*/

#include <iostream>
#include <algorithm>

#include "p10.h"


using namespace std;

//make two non-member functions min and max to compare values and pick the
//lowest and highest

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
0. also initialize a ton of arrays so we can do visiteds and the whole dijkstra
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
    int vCount = 0;
    int eCount = 0;
    lambda = new int[n];
    set = new int[n];
    visited = new bool[n];
    predecessor = new int[n];
}

//******************************************************************************

/*Bella
clear out all the arrays by setting the whole thing to 0 and then deleting the
pointer array. also delete the labels intlist and all of the new things we added
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
    int rc = -1;
    labels->readAt(vid, rc);
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
    
        if (!V) {
            newCount++;
        }
        if (!U) {
            newCount++;
        }
        if (n - vCount >= newCount) {
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
        for (int i = 0; i <= vCount; i++) {
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
    int r, c;

    cout << "Graph info:\n";
    cout << "  Graph size = " << sizeV() << endl;
    cout << "  vCount = " << sizeUsedV() << endl;
    cout << "  eCount = " << sizeE() << endl;
    cout << "\nGraph contents:\n";
    for (int r = 0; r < sizeUsedV(); r++) {
        int label;
        labels->readAt(r, label);
        cout << "  Node(" << r << "," << label << "):";
        for (c = 0; c < sizeUsedV(); c++) {
            cout << " " << a[ind(r,c)];
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
search that bread!! just kidding.
*/

void Graph::breadthFirstSearch(int u, bool key) const {
    if (u >= 0) {
        int val = 0;
        int i = 0;
        bool* visited = new bool[vCount];
        for (int i = 0; i < vCount; i++) {
            visited[i] = false;
        }
        q->clear();
        visited[u] = true;
        q->enq(u);
        i = 0;
        while (q->count()) {
            q->deq(val);
            if (key) {
                int label;
                labels->readAt(val, label);
                cout << "Item " << i++ << " is (" << label << ")" << endl;
            }
            for (int v = 0; v < vCount; v++) {
                if (isEdge(vidToLabel(u), vidToLabel(v))) {
                    if(!visited[v]) {
                        visited[v] = true;
                        q->enq(v);
                    }
                }
            }
        }
    }
}

//******************************************************************************

/*Bella
print up the nodes and stuff
*/

void Graph::bfPrint(int label) const {
    int v = labelToVid(label);
    if (v >= 0) {
        breadthFirstSearch(v, true);
    }
}

//******************************************************************************

/*Bella
print out a very nice list of the nodes and the matrix with the weights in their
correct spots. Also print the count of vertices and edges and all the things
so we can double-check that it actually works.
*/

void Graph::printPaths() const {
    int u = 0;
    int v = 0;
    for (int i = 0; i < vCount; i++) {
        u = vidToLabel(i);
        for (int j = 0; j < vCount; j++) {
            v = vidToLabel(j);
            if (isPath(u, v)) {
                cout << u << " does have a path to " << v << endl;
            } else {
                cout << u << " does not have a path to " << v << endl;
            }
        }
    }
}

//******************************************************************************
/*Kandice
set up the private dijkstra that recieves an int input
*/

void Graph::dijkstra (int s) {
    int i;
    for (i = 0; i < n; ++i) {
        lambda[i] = INFINITE;
        set[i] = X;
    }
    
    lambda[s] = 0;
    
    // Dijkstra's algorithm
    while (minLambdaY(s)) {
        int minV;
        set[minV] = Y;    
        for (int v = 0; v < n; ++v) {
            if (a[minV][v] > 0 && set[v] == X) {
                lambda[v] = min(lambda[v], lambda[minV] + a[minV][v]);
            }
        }
        
    }
}

//******************************************************************************

/*Bella
calculate the minimum distance from each node to the rest. set it up in the
arrays and move things around as necessary. were gonna need this for the
dijkstra algorithm so make sure it works 
*/

bool Graph::minLambdaY(int &minV) {
    bool rc = false;
    int minVal = INFINITE;
    minV = -1;
    for (int i = 0; i < vCount; i++) {
        if (set[i] == Y) {
            if (lambda[i] <= minVal) {
                minVal = lambda[i];
                rc = true;
            }
        }
    }
    return rc;
}

//******************************************************************************

/*Kandice
*/
bool Graph::dijkstra (int sLabel, int dLabel, int &distance) {
    int s = labelToVid(sLabel);
        int d = labelToVid(dLabel);

        // Check if the labels correspond to valid vertices
        if (s == -1 || d == -1) {
            distance = -1;
        } else {
            dijkstra(s);

            // Check if the destination vertex is reachable
            distance = lambda[d];
        }

        // Always return true; the result is now determined by the 'distance' 
		//value
        return true;
}
