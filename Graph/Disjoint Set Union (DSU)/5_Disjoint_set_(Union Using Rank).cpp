// just for reference or quick use 

// Code For Find Path Compression

int find(int i, vector<int> & parent) {
    if ( i == parent[i] ) {
        return i;
    }

    return parent[i] = find(parent[i], parent);
}

// Code for Union() Using Rank
// Code For Union By Rank


void union(int x, int y, vector<int> parent, vector<int> & rank ) {
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if ( rank[x_parent] > rank[y_parent] ) {
        parent[y_parent] = x_parent;
    }
    else if ( rank[y_parent] < rank[x_parent] )
    {
        parent[x_parent] = y_parent;
    }
    else {
        parent[x_parent] = y_parent;
        rank[y_parent] += 1;
    }
}