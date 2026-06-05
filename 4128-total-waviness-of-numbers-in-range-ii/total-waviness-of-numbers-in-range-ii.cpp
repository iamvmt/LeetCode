class Solution {
public:

    vector<int> d ;
    long long dp[50][50][11][11][2][2] ; // DP for Position , Sum , Previous 's Previous , Previous , Small and Non - zero( NZ)

    long long solve( int pos , int sum , int pre2 , int pre , bool small , bool nz  ){

        if( pos == d.size()) return sum ; 

        if( dp[pos][sum][pre2][pre][small][nz] != -1 ){

            return dp[pos][sum][pre2][pre][small][nz] ;

        }

        int limit = ( small ? 9 : d[pos]) ;
        long long ans = 0 ; 

        for( int i = 0 ; i <= limit ; i++ ){

            bool newsmall = ( small || i < d[pos]) ; 
            bool newnz = ( nz || (i!=0) ) ;

            if( newnz ){ // New non zero
                
                //NEW values 
                int npre2 = pre ;
                int npre = i ; 
                int nsum = sum ;

                if( pre2 != 10 && pre != 10 ){

                    nsum += (pre2 < pre && i < pre ) ; // PEAK
                    nsum += (pre2 > pre && i > pre ) ; // VALLEY

                }

                ans += solve( pos + 1 , nsum , npre2 , npre , newsmall , newnz) ;
            }

            else {
                ans += solve( pos + 1 , sum , pre2 , pre , newsmall , newnz) ;

            }
        }
        return dp[pos][sum][pre2][pre][small][nz] = ans ;

    }
    long long count( long long n ){
        if( n == 0 ) return 0 ; 
        d.clear() ; 

        while( n ){
            d.push_back( n % 10 ) ;
            n = n / 10 ;
        }

        reverse( d.begin() , d.end() ) ;
        memset( dp , -1 , sizeof(dp) ) ;

        return solve(0 , 0 , 10 , 10 , 0 , 0) ;

    }
    long long totalWaviness(long long num1, long long num2) {

        return count(num2) - count(num1 - 1 ) ;
        
    }
};