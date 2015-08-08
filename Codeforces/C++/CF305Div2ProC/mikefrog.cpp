#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

LL m , h1 , h2 , a1 , a2 , y1 , y2 , x1 , x2 , d1 , d2 , n1 , n2 ;
LL P1[3] , P2[3] , i ;

int main() {
	cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2 ;
	for ( P1[0] = P2[0] = 0 , i = 0 ; i < 2*m && (P1[0] < 2 || P2[0] < 2) ; i ++ ) {
		if ( h1 == a1 && P1[0] < 2 ) P1[++P1[0]] = i ;
		if ( h2 == a2 && P2[0] < 2 ) P2[++P2[0]] = i ;
		h1 = (h1 * x1 + y1) % m ;
		h2 = (h2 * x2 + y2) % m ;
	}
	
	if ( P1[0] == 0 || P2[0] == 0 ) cout << "-1\n" ;
	else {
		d1 = P1[2] - P1[1] ;
		d2 = P2[2] - P2[1] ;
		n1 = P1[1] ;
		n2 = P2[1] ;
		
		for ( i = 0 ; i < m*10 ; i ++ ) {
			if			( n1  < n2 ) n1 += d1 ;
			else if		( n2  < n1 ) n2 += d2 ;
			else if		( n1 == n2 ) { cout << n1 << "\n" ; break ; }
		}
		if ( i == m*10 ) cout << "-1\n" ;
	}
}