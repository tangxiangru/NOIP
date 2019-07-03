#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
const int N = 100000 + 11 ;
using namespace std ;
int n , m , dis[N] ;
bool used[N] ;
struct id
{
    int l , r ;
} links[N] ;

void Init( )
{
    scanf( "%d%d" , &n , &m ) ; int a , b , c ;
    for( int x = 1 ; x <= m ; ++x )
    {
        scanf( "%d%d%d" , &a , &b , &c ) ;
        links[a].l = b , links[a].r = c ;
    }
}


queue< int > Q ; 
void Solve( )
{
    memset( dis , 127/2 , sizeof( dis ) ) ;
    dis[1] = 1 ; Q.push( 1 ) ; used[1] = 1 ;
    while( !Q.empty( ) )
    {
        int u = Q.front( ) ; Q.pop( ) ;
        int l = links[u].l ;
        if( dis[l] > dis[u] + 1 )
        {
            dis[l] = dis[u] + 1 ;
            if( ! used[l] )
            {
                used[l] = true ;
                Q.push( l ) ;
            }
        }
        int r = links[u].r ;
        if( dis[r] > dis[u] + 1 )
        {
            dis[r] = dis[u] + 1 ;
            if( !used[r] )
            {
                used[r] = true ;
                Q.push( r ) ;
            }
        }
    }
}

void Output( )
{
    for( int x = 1 ; x <= n ; ++x )
        printf( "%d\n" , dis[x] ) ;
}


int main( )
{
    freopen( "2359.in" , "r" , stdin ) ;
    freopen( "2359.out" , "w" , stdout ) ;
    Init( ) ;
    Solve( ) ;
    Output( ) ;
    fclose( stdin ) ;
    fclose( stdout ) ;
    return 0 ;
}
