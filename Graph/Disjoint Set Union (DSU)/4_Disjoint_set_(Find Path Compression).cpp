// just for reference or quick use 

// Code For Find Path Compression

int find(int i, vector<int> & parent) {
    if ( i == parent[i] ) {
        return i;
    }

    return parent[i] = find(parent[i], parent);
}



// performance improvement
