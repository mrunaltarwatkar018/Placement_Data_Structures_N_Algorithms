// just for reference or quick use 


// Code For Find

int find(int i, vector<int> & parent) {
    if ( i == parent[i] ) {
        return i;
    }

    return find(parent[i], parent);
}