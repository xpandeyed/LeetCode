class Solution {
public:
    
    int m;
    int n;
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        m = grid.size();
        n = grid[ 0 ].size();
        
        if( k >= m + n - 2 ) {
            return m + n - 2;
        }
        
        vector<vector<int>> visited( m, vector<int>( n, k + 1 ) );
        int rowDir[ 4 ] = { 0, 0, 1, -1 };
        int colDir[ 4 ] = { 1, -1, 0, 0 };
        
        queue<vector<int>> q;
        queue<vector<int>> qNext;
        int count = 0;

        q.push( { 0, 0, 0 } );
        visited[ 0 ][ 0 ] = true;

        while( !q.empty() ) {
            int row = q.front()[ 0 ];
            int col = q.front()[ 1 ];
            int used = q.front()[ 2 ];
            q.pop();
            
            if( used > visited[ row ][ col ] ) {
                continue;
            }
            
            if( row == m - 1 && col == n - 1 ) {
                return count;
            }
            
            for( int i = 0; i < 4; ++i ) {
                int rowNext = row + rowDir[ i ];
                int colNext = col + colDir[ i ];
                
                if( checkRange( rowNext, colNext ) == false ) {
                    continue;
                }

                int usedNext = used + grid[ rowNext ][ colNext ];
                if( usedNext >= visited[ rowNext ][ colNext ] ) {
                    continue;
                }

                visited[ rowNext ][ colNext ] = usedNext;
                qNext.push( { rowNext, colNext, usedNext } );
            }
            
            if( q.empty() ) {
                ++count;
                swap( q, qNext );
            }
        }
        
        return -1;
    }
    
    bool checkRange( int row, int col ) {
        
        if( row < 0 || col < 0 || row >= m || col >= n ) {
            return false;
        }
        
        return true;
    }
};